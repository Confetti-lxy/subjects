#include <stdio.h>

void DigiTran(int val, char res[]);

int main()
{
    int val = 0;
    while ((scanf("%d", &val)) != -1)
    {
        char res[10004];
        DigiTran(val, res);
    }
}

void DigiTran(int val, char res[])
{
    int index = 0, flag = 0, change_value = 0;
    if (val % 10 == 0)
    {
        flag = 1;
    }
    while (val != 0)
    {
        int temp = val % 10;
        change_value = change_value * 10 + temp;
        val /= 10;
    }
    while (change_value >= 10)
    {
        int temp1 = change_value % 10, temp2 = (change_value % 100) / 10;
        int key = temp1 * 10 + temp2;
        if (key < 26)
        {
            res[index] = 'A' + key;
            index++;
        }
        else
        {
            res[index] = 'A' + temp1;
            index++;
            res[index] = 'A' + temp2;
            index++;
        }
        change_value /= 100;
    }
    if (change_value != 0)
    {
        res[index] = 'A' + change_value;
    }
    for (int i = 0; i < index; i++)
    {
        printf("%c", res[i]);
    }
    if (flag == 1)
    {
        printf("A");
    }
    printf(" ");
    return;
}