import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import GridSearchCV

df_train = pd.read_csv('titanic_train.csv')
df_test = pd.read_csv('titanic_test.csv')
df_test['Survived'] = np.NaN

df = pd.concat([df_train,df_test],axis=0,ignore_index=True)

#Cleaning Data

def clean_nan_age(cols):
    Age = cols[0]
    Pclass = cols[1]
    if pd.isnull(Age):
        if Pclass == 1:
            return df['Age'][df['Pclass']==Pclass].mean()
        if Pclass == 2:
            return df['Age'][df['Pclass']==Pclass].mean()
        if Pclass == 3:
            return df['Age'][df['Pclass']==Pclass].mean()
    else:
        return Age
    
df['Age'] = df[['Age','Pclass']].apply(clean_nan_age,axis=1) 


df['Fare'].fillna(df['Fare'].fillna(df['Fare'][df['Pclass']==3].mean()),inplace=True)

df['Embarked'].fillna(df['Embarked'].value_counts().idxmax(),inplace=True)
df_emb = pd.get_dummies(df['Embarked'],columns='Embarked',prefix='Embarked')
df = pd.concat([df.drop('Embarked',axis=1),df_emb],axis=1)

df_sex = pd.get_dummies(df['Sex'],columns='Sex',prefix='Sex')
df = pd.concat([df.drop('Sex',axis=1),df_sex],axis=1)


df['Title'] = df['Name'].apply(lambda name:name.split(', ')[1].split('.')[0])
df_title = pd.get_dummies(df['Title'],columns='Title',prefix='Title')
df = pd.concat([df.drop('Title',axis=1),df_title],axis=1)

df['Cabin'] = df['Cabin'][df['Cabin'].notnull()].apply(lambda cabin:cabin[0])
df['Cabin'] = df['Cabin'].fillna('No Cabin')
df_cabin = pd.get_dummies(df['Cabin'],columns='Cabin',prefix='Cabin')
df = pd.concat([df.drop('Cabin',axis=1),df_cabin],axis=1)


df['Fam_size'] = df['Parch'] + df['SibSp']
df['Alone'] = df['Fam_size'].apply(lambda size:1 if size==0 else 0)
df['Small_Fam'] = df['Fam_size'].apply(lambda size:1 if size<2 else 0)
df['Medium_Fam'] = df['Fam_size'].apply(lambda size:1 if size>2 & size<5 else 0)
df['Big_Fam'] = df['Fam_size'].apply(lambda size:1 if size>5 else 0)

df_pclass = pd.get_dummies(df['Pclass'],columns='Pclass',prefix='Pclass')
df = pd.concat([df.drop('Pclass',axis=1),df_pclass],axis=1)

# Modeling
X_train = df.iloc[0:len(df_train)].drop(['Name','PassengerId','Ticket','Survived'],axis=1)
y_train = df.iloc[0:len(df_train)]['Survived']
X_test = df.iloc[len(df_train):len(df)].drop(['Name','PassengerId','Ticket','Survived'],axis=1)

rfc = RandomForestClassifier(n_estimators=100,min_samples_leaf=50)
rfc.fit(X_train, y_train)
y_pred=rfc.predict(X_test).astype(int)
print('Score: ',rfc.score(X_train,y_train))

# Optimizing the model parameters
rfc_param_grid = {"max_features": [1, 3, 10],
              "min_samples_split": [2, 3, 10],
              "min_samples_leaf": [1, 25, 50],
              "n_estimators" :[100,300]}
rfc_grid_search = GridSearchCV(rfc,param_grid = rfc_param_grid, scoring="accuracy", n_jobs= 4, verbose = 1)
rfc_grid_search.fit(X_train,y_train)

rfc_grid_search_best = rfc_grid_search.best_estimator_

y_pred=rfc_grid_search_best.predict(X_test).astype(int)
print(rfc_grid_search.best_score_)

res = pd.DataFrame(data = y_pred, index = np.arange(892,892+len(y_pred)), columns = ['Survived'])
res.index.name = 'PassengerId'
res.to_csv('results.csv')
print('Done!')