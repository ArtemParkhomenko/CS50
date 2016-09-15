#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>

const int MAX_ARRAY_LENGHT = 11;
const int ADMIN_PASSWORD = 1111;

int main()
{
    setlocale(LC_ALL,"");
    printf("Здравствуйте!!\n");
    execute();
    return 0;
}

void execute ()
{
    int array[MAX_ARRAY_LENGHT];
    int index = -1;
    int password = 0;
    arrayRandom(array);
    printf("Введите ячейку: ");
    scanf("%d",&index);
    if (index==0 && validationCheck(index))
    {
        printf("\nВведите пароль: ");
        scanf("%d", &password);
        if (password==ADMIN_PASSWORD)
            selectOperation(array,index);
        else
        {
            printf("\nПароль не верный. Операции будут завершенны.");
        }
    }
    else if (validationCheck(index)==true)
        selectOperation(array,index);
    else
    {
        printf("\nНе верный номер ячейки. Дальнейшие операции будут завершенны.");
    }
}


void arrayRandom(int* array)
{
    array[0] = 20000;
    srand(time(NULL));
    for(int i = 1; i<MAX_ARRAY_LENGHT; i++)
    {
        array[i] = 100 + rand() % 1000;
    }
}

int validationCheck(int index)
{
    if(index>=0 && index<MAX_ARRAY_LENGHT)
        return true;
    else
        return false;
}
void selectOperation(int* array, int index)
{
    printf("\nВаша ячейка №%d готова для дальнейших операций \n",index);
    printOperation();
    int number = 0;
    int soum = 0;
    int temp = 0;
    scanf("%d",&number);
    while(true)
    {
        if(number==1)
        {
            printf("Ваш баланс = %d\n", array[index]);
            printOperation();
            scanf("%d", &number);
            continue;
        }
        else if (number==2)
        {
            printf("Введите суму которую хотите снять: ");
            scanf("%d",&soum); // Сделать проверку на ввод сумы не меньше>0 и меньше <50000
            if (soum<=array[index])
            {
                printf("\nОперация успешно выполнена, Вы, сняли %d кредитов.\n",soum);
                temp=array[index]-soum;
                printf("Остаток на счету = %d\n", temp);
                break;
            }
            else
            {
                printf("Не достаточно на счету!", temp);
                break;
            }
        }
        else if (number==3)
        {
            break;
        }
        else
        {
            printf("\nНекорректный выбор операции. Повторити попытку еще раз: ");
            scanf("%d",&number);
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
