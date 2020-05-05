#! /bin/bash

cp list.* test_list

cd test_list

rm -f *.o

gcc -c *.c

if [ $? == 0 ]
then
  gcc -o test_list *.o

  if [ $? == 0 ]
  then
    rm -f *.o
    rm list.*

    ./test_list
  else
    echo "Linking Failed."
  fi

else
  echo "Compilation Error."
fi
