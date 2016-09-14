#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

const int ARRAY_SIZE = 11;
const int ADMIN_PASSWORD = 1111;

int main()
{
    setlocale(LC_ALL,"");
    int array[ARRAY_SIZE];
    arrayInitialization(array);
    execution(array);
    return 0;
}

void arrayInitialization(int* array)
{
    array[0]=20000;
    srand (time(NULL));
    for (int i = 1; i<=10; i++)
    {
        array[i] = 100 + rand() % 1000;
    }
     for (int i = 0; i<11; i++)
    {
        printf("i[%d] = ",i);
        printf("%d \n",array[i]);
    }
}

void execution(int* array)
{
    int index;
    int password;
    printf("Введите номер ячейки от 1 до 10 : ");
    scanf("%d", &index);
    while(true)
    {
        if (index>0 && index<=10)
        {
            selectionOfOperations(array,index);
            break;
        }
        else if(index == 0)
        {
            printf("Введите пароль: ");
            scanf("%d", &password);
            if (password==ADMIN_PASSWORD)
            {
                selectionOfOperations(array,index);
                break;
            }
            else
            {
                printf("Не верный пароль. Операция завершенна!");
                break;
            }
        }
        else
        {
            printf("Введен не верный номер ячейки. Повторите еще раз: ");
            scanf("%d", &index);
            continue;
        }
    }
}

void selectionOfOperations(int* array,int index)
{
    printf("\nЗдравствуйте! Ваша ячейка №%d готова для дальнейших операций \n",index);
    printOperation();
    char c;
    int soum = 0;
    scanf("%s", &c);
    while(true)
    {
        if(c=='1')
        {
            printf("Ваш баланс = %d\n",array[index]);
            printOperation();
            scanf("%i", &c);
            continue;
        }
        else if (c=='2')
        {
            printf("Введите суму которую хотите снять: ");
            scanf("%d",&soum);
            if (soum<array[index])
            {
                printf("Операция успешно выполнена, Вы, сняли %i \n", soum);
            }
            else
            {
                printf("\nНе достаточна на счету!\n");

            }
            printOperation();
            scanf("%s", &c);
            continue;
        }
        else if (c=='3')
        {
            break;
        }
        else
        {
            printf("\nНе корректный ввод. Повторите еще раз: ");
            scanf("%s", &c);
            continue;
        }

    }

}
void printOperation()
{
    printf("\nВсе возможные операции: \n");
    printf("1. Проверить счет \n");
    printf("2. Снять деньги со счета \n");
    printf("3. Выход \n");
    printf("\nДля выбора введите номер операции: ");
}
