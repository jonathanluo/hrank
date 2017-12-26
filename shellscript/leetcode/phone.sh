#!/bin/bash
echo "Enter a phone number as XXXXXXXX: "
read phoneNumber
pat="^[0-9]{3}\-[0-9]{3}\-[0-9]{4}$"
while [[ ! $phoneNumber =~ $pat ]]
    do
    echo "Please enter a phone number as XXXXXXXX: "
    read phoneNumber
done
echo $phoneNumber

pat="^\([0-9]{3}\) [0-9]{3}\-[0-9]{4}$"
while [[ ! $phoneNumber =~ $pat ]]
    do
    echo "Please enter a phone number as XXXXXXXX: "
    read phoneNumber
done
echo $phoneNumber



