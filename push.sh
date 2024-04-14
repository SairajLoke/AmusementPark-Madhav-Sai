#!/bin/bash
# current_date=$(date +"%Y-%m-%d")
# echo "Message : "
read -p "Message : " mess
git checkout master
# echo "Current date is: $current_date"
git pull
git add .
git commit -m "$mess"
git push -u origin master