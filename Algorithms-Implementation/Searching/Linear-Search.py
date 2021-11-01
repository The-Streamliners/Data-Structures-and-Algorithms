def search(l,to_search):
  for e in l:
    if e==to_search:
      print("Position of %d is:"%to_search,l.index(e)+1)
      break
  else:print('Position Not Found For ',to_search)
lis,x=[1,5,6,3,-5,-4,0,2,-14,45],0
search(lis,x)
search(lis,100)
