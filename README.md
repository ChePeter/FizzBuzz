# FizzBuzz
 FizzBuzz by pensioner's


Это пост и код написаны по результатам прочтения и изучения статьи @qrdl 
" FizzBuzz по-сениорски " https://habr.com/ru/post/540136/

Получилось FizzBuzz по пенсионерски.

Для сравнения выбрал код https://github.com/qrdl/fizzbuzz/blob/main/customprint2.c так как с интрисиками что-то мой нотбук дает ошибку и лень разбираться. Да и не во всех процессорах они есть и прекрасно можно обойтись без них.

Чтобы сравнить чисто код вычислений, в программе customprint2.c убрал 60 строку. Это вывод
fwrite(cur, wrkbuf + CHUNK_SIZE - cur, 1, stdout);

Замеры проводил вот так

#!/bin/bash
gcc -O3 -march=native customprint2.c -o customprint2
basetime=$(date +%s%N)
./customprint2 > /dev/null
echo "runtime: $(echo "scale=3;($(date +%s%N) - ${basetime})/(1*10^09)" | bc) seconds"

Если оставить fwrite
runtime: 6.954 seconds

Если убрать fwrite
runtime: 4.443 seconds

Т.е. в сеньорской программе собственно расчеты составляют 4.4 сек.
Ну норм, наверно, для сеньора.

Теперь запустим пенсионерский вариант

Если оставить fwrite ( это 68, 73 и 114 строки)
runtime: 2.777 seconds

Если убрать fwrite
runtime: 1.417 seconds

Всё это на машине 
model name      : Intel(R) Core(TM) i5-9400T CPU @ 1.80GHz

