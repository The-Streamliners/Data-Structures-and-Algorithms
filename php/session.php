<?php

/**
 * @author santhu
 * @copyright 2019
 */
session_start();
if(!@$_COOKIE["Online"])
{
    
}
else
{
    $txt = md5(substr(str_shuffle("Online"),0));

    setcookie("Online", $txt, time()+30*15);
    
    $admin_id = $_SESSION['Online_user'];
    $unique_id = $_SESSION['Online_id'];    
    
}

function dateCovert($date){
    $new = explode("-",$date);
    
    $return["maindate"] = $date;
    $return["year"] = $new[0];
    if(count($new) == 3)
    {
        $return["date"] = $new[2]."-".$new[1]."-".$new[0];
        $return["mntName"] = date('F', mktime(0, 0, 0, $new[1]));
        $return["day"] = $new[2];
        $return["mnt"] = $new[1];   
    }
    else
    if(count($new) == 2)
    {
        $return["date"] = $new[1]."-".$new[0];
        $return["mntName"] = date('F', mktime(0, 0, 0, $new[1]));
        $return["mnt"] = $new[1];
        
    }    
    return $return;
}
?>