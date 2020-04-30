#! /bin/bash
rm -f *.o
gcc -c *.c
if [ $? == 0 ]
then
  gcc -o numbers *.o
  if [ $? == 0 ]
  then
    rm -f *.o
    ./numbers
  else
    echo "Linking Failed."
  fi
else
  echo "Compilation Error."
fi
