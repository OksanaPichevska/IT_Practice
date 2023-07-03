#include <stdio.h>

#define MOD 12345

int main() {
    int n;
    printf("Введіть довжину послідовності n (1 < n < 10000): ");
    scanf("%d", &n); //зчитування довжини послідовності

    int dp[n+1]; /*використовуємо масив dp для збереження кількості допустимих послідовностей довжиною i, 
    де не зустрічаються три одиниці підряд */
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 3;
    /*починаємо з визначення початкових значень dp[0], dp[1] і dp[2]. Потім використовуємо цикл for, 
    щоб обчислити значення dp[i] для кожного i від 3 до n. На кожній ітерації використовуємо 
    рекурентне співвідношення dp[i] = dp[i-1] + dp[i-2], а також застосовуємо модульну арифметику з 
    використанням оператора % MOD, щоб уникнути переповнення при обчисленні великих чисел */
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD; /*Модульність - це операція, яка повертає залишок від ділення 
        одного числа на інше. В даному випадку, ми застосовуємо модульну арифметику з базовим числом 12345, 
        щоб забезпечити, що значення dp[i] не буде перевищувати це число */
    }

    printf("Кількість шуканих послідовностей: %d\n", dp[n]);

    return 0;
}
