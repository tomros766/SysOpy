#!/bin/bash

`touch results3a.txt`
`echo "static: \n" >> results3a.txt`
`make zad3_static >> results3a.txt`
`echo " shared: \n" >> results3a.txt`
`make zad3_shared >> results3a.txt`

