#! /bin/bash

cp list.* tests

cd tests

rm -f *.o

gcc -c *.c

if [ $? == 0 ]
then
  gcc -o tests *.o

  if [ $? == 0 ]
  then
    rm -f *.o
    rm list.*

    ./tests
  else
    echo "Linking Failed."
  fi

else
  echo "Compilation Error."
fi
