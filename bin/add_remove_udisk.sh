#!/bin/sh  
if [ $ACTION = "add" ];   
then   
    mount /dev/$MDEV /mnt;   
else   
    umount /mnt;   
fi  
