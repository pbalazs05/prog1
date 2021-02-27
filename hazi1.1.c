#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*még meglehetne számolni hány nap van a felhasználó születésnapjáig ha nem az adott napon van
        illetve hogy mennyi telt már el az adott évi születésnaptol és akkor mennyi van még hátra a következő évi-ig*/

int main()
{
    int nap = 0;
    int honap = 0;
    int ev = 0;
    time_t t = time(NULL);
    struct tm time = *localtime(&t);

    char s[1000];
    char uzenet_a[] = "Add meg a születési dátumodat, szóközzel elválasztva (év honap nap)";
    char uzenet_b[] = "Reális születési dátumot adj meg!\n";

    printf("Add meg a neved\n");
    gets(s);

    puts(uzenet_a);

    char s1[1000];
    gets(s1);
    char *token = strtok(s1, " ");

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            ev = atoi(token);
        }
        if (i == 1)
        {
            honap = atoi(token);
        }
        if (i == 2)
        {
            nap = atoi(token);
        }
        token = strtok(NULL, " ");
    }

    //  scanf("%d %d %d", &ev, &honap, &nap);

    if (ev >= 1900 && ev <= 2100)
    {
        if (honap == 2)
        {
            if (nap < 30 && nap > 0)
            {
                if ((honap == time.tm_mon + 1) && (nap == time.tm_mday))
                {
                    //printf("%d:%d:%d", time.tm_year+1900, time.tm_mon+1, time.tm_mday);
                    int kor = (time.tm_year + 1900) - ev;
                    printf("Boldog %d-ik születesnapot ", kor);
                    puts(s);
                }
                else
                {
                    printf("Sajnos ez nem a te napod ");
                    puts(s);
                }
            }
            else
            {
                printf("ne szórakozz februárban legfeljebb 29 nap lehet!");
            }
        }
        else if (honap == 4 || 6 || 9 || 11)
        {
            if (nap < 31 && nap > 0)
            {
                if ((honap == time.tm_mon + 1) && (nap == time.tm_mday))
                {
                    //printf("%d:%d:%d", time.tm_year+1900, time.tm_mon+1, time.tm_mday);
                    int kor = (time.tm_year + 1900) - ev;
                    printf("Boldog %d-ik születesnapot ", kor);
                    puts(s);
                }
                else
                {
                    printf("Sajnos ez nem a te napod ");
                    puts(s);
                }
            }
            else
            {
                printf("ne szórakozz a %d. hónapban csak 30 nap van!", honap);
            }
        }
        else if (honap == 1 || 3 || 5 || 7 || 8 || 10 || 12)
        {
            if (nap < 32 && nap > 0)
            {
                if ((honap == time.tm_mon + 1) && (nap == time.tm_mday))
                {
                    //printf("%d:%d:%d", time.tm_year+1900, time.tm_mon+1, time.tm_mday);
                    int kor = (time.tm_year + 1900) - ev;
                    printf("Boldog %d-ik születesnapot ", kor);
                    puts(s);
                }
                else
                {
                    printf("Sajnos ez nem a te napod ");
                    puts(s);
                }
            }
            else
            {
                printf("ne szórakozz a %d. hónapban csak 31 nap van!", honap);
            }
        }

    }
    else
    {
        puts(uzenet_b);
    }

    return 0;
}
