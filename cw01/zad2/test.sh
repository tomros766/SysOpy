#!/bin/bash
`touch raport2.txt`
`echo 'mała ilość tych samych plików : ' >> raport2.txt`
`./main create_table 100 compare_pairs a.txt:a.txt b.txt:b.txt c.txt:c.txt >> raport2.txt`
`echo 'duza ilosc tych samych plikow: ' >> raport2.txt`
`./main create_table 100 compare_pairs a.txt:a.txt b.txt:b.txt c.txt:c.txt d.txt:d.txt e.txt:e.txt f.txt:f.txt >> raport2.txt`
`echo 'mala ilosc roznych plikow: ' >> raport2.txt`
`./main create_table 100 compare_pairs a.txt:b.txt c.txt:d.txt e.txt:f.txt >> raport2.txt`
`echo 'duza ilosc roznych plikow: ' >> raport2.txt`
`./main create_table 100 compare_pairs a.txt:b.txt a.txt:c.txt a.txt:d.txt a.txt:e.txt a.txt:f.txt b.txt:c.txt b.txt:d.txt b.txt:e.txt b.txt:f.txt c.txt:e.txt d.txt:f.txt d.txt:e.txt >> raport2.txt`
`echo 'duza ilosc roznych plikow i usuwanie wybranych blokow: ' >> raport2.txt`
`./main create_table 100 compare_pairs a.txt:b.txt a.txt:c.txt a.txt:d.txt a.txt:e.txt a.txt:f.txt b.txt:c.txt b.txt:d.txt b.txt:e.txt b.txt:f.txt c.txt:e.txt d.txt:f.txt d.txt:e.txt remove_block 1 remove_block 3 remove_block 5 compare_pairs b.txt:c.txt remove_block 2 >> raport2.txt`

