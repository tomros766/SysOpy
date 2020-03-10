#!/bin/bash


`touch results3b.txt`
`echo "static opt 1: " >> results3b.txt`
`make zad3b_static0 >> results3b.txt`
`echo "static opt 2: " >> results3b.txt`
`make zad3b_static1 >> results3b.txt`
`echo "static opt 3: " >> results3b.txt`
`make zad3b_static2 >> results3b.txt`
`echo "shared opt 1: " >> results3b.txt`
`make zad3b_shared0 >> results3b.txt`
`echo "shared opt 2: " >> results3b.txt`
`make zad3b_shared1 >> results3b.txt`
`echo "shared opt 3: " >> results3b.txt`
`make zad3b_shared2 >> results3b.txt`

