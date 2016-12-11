#include <stdio.h>  // Для printf
#include <time.h>   // Для time, ctime

int main (void)
{    
   // Переменная для сохранения текущего времени
   long int ttime;

   // Считываем текущее время
   ttime = time (NULL);

   // С помощью функции ctime преобразуем считанное время в
   // локальное, а затем в строку и выводим в консоль.
   printf ("Время: %s\n",ctime (&ttime) );
   
   system('pause');
   return 0;

}