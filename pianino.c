#include <stdio.h>
#include <windows.h>
#include <time.h>
char klawisz;
const int czasTrwaniaDzwieku = 100;
void pianino()
{
    printf( "|  | | | |  |  | | | | | |  |   | | | | |  | | | \n"
            "|  |w| |e|  |  |t| |y| |u|  |   |o| |p| |  |]| | \n"
            "|  |_| |_|  |  |_| |_| |_|  |   |_| |_| |  |_| |_\n"
            "|   |   |   |   |   |   |   |   |   |   |   |   |\n"
            "| a | s | d | f | g | h | j | k | l | ; | ' | \\ |\n"
            "|___|___|___|___|___|___|___|___|___|___|___|___|\n");
}

void rozpoczecie()
{
    system("cls");
    printf("MENU: \n1. Tryb wolny<--\n2. Nagrywaj\n3. Posluchaj\n4. Odtworz ostatnie nagranie\n5. Wyjdz z programu\n\n");
    pianino();
    printf("\nGraj...");
        while(1)
        {
            klawisz = getch();
            switch(klawisz)
            {
                case '1': rozpoczecie(); break;
                case '2': nagrywaj(); break;
                case '3': posluchaj(); break;
                case '4': odczyt(); break;
                case '5': koniec(); break;
            }
           dzwiek(); //UWAGA: jesli nie zakonczysz nastepnych funkcji to sie odtworzy!
        }
}

void koniec()
{
    while(1)
    {
        system("cls");
        printf("MENU: \n1. Tryb wolny\n2. Nagrywaj\n3. Posluchaj\n4. Odtworz ostatnie nagranie\n5. Wyjdz z programu<--\n\n");
        pianino();
        printf("\nJestes pewien, ze chcesz zakonczyc prace z programem? T/N\n");
        klawisz = getch();
        switch(klawisz)
        {
            case 't': exit(0); break;
            case 'n': rozpoczecie(); break;
        }
        printf("Bledny wybor\n");
        Sleep(500);
    }
}

void nagrywaj()
{
    int i=-1;//i=-1 w dalszej czesci konieczny warunek
    clock_t start,stop;
    system("cls");
    printf("MENU: \n1. Tryb wolny\n2. STOP<--\n3. Posluchaj\n4. Odtworz ostatnie nagranie\n5. Wyjdz z programu\n\n");
    pianino();
    FILE *fzapis;
    fzapis=fopen("zapis.txt","w");
    printf("\nNagrywam...\n");
    while(1)
    {
        dzwiek();
        klawisz=getch();
        switch(klawisz)
        {
            case '1':
                printf("STOP zapisywanie...\n");
                Sleep(1000);
                fclose (fzapis);
                rozpoczecie(); break;
            case '2':
                printf("Zapisywanie utworu...\n");
                Sleep(1000);
                fclose (fzapis);
                rozpoczecie();break;
            case '3':
                printf("STOP zapisywanie...\n");
                Sleep(1000);
                fclose (fzapis);
                posluchaj(); break;
            case '4':
                printf("STOP zapisywanie...\n");
                Sleep(1000);
                fclose (fzapis);
                odczyt(); break;
            case '5':
                printf("STOP zapisywanie...\n");
                Sleep(1000);
                fclose (fzapis);
                koniec(); break;
        }
        if(i>=0)
        {
            stop=clock();
            fprintf (fzapis, "%d\n", stop - start - czasTrwaniaDzwieku);//liczy czas odstepu pomiedzy nutami
        }
        fprintf (fzapis, "%c\n", klawisz);
        i++;//dlugosc
        start=clock();
    }
}

void dzwiek()
{
    if(klawisz == 'a')Beep(261,czasTrwaniaDzwieku); //c
    if(klawisz == 's')Beep(293,czasTrwaniaDzwieku); //d
    if(klawisz == 'd')Beep(329,czasTrwaniaDzwieku); //e
    if(klawisz == 'f')Beep(349,czasTrwaniaDzwieku); //f
    if(klawisz == 'g')Beep(392,czasTrwaniaDzwieku); //g
    if(klawisz == 'h')Beep(440,czasTrwaniaDzwieku); //a
    if(klawisz == 'j')Beep(493,czasTrwaniaDzwieku); //h
    if(klawisz == 'k')Beep(523,czasTrwaniaDzwieku); //c
    if(klawisz == 'l')Beep(587,czasTrwaniaDzwieku); //d
    if(klawisz == ';')Beep(659,czasTrwaniaDzwieku); //e
    if(klawisz == '\'')Beep(698,czasTrwaniaDzwieku); //f
    if(klawisz == '\\')Beep(784,czasTrwaniaDzwieku); //g

    if(klawisz == 'w')Beep(277,czasTrwaniaDzwieku); //cis
    if(klawisz == 'e')Beep(311,czasTrwaniaDzwieku); //dis
    if(klawisz == 't')Beep(370,czasTrwaniaDzwieku); //fis
    if(klawisz == 'y')Beep(415,czasTrwaniaDzwieku); //gis
    if(klawisz == 'u')Beep(466,czasTrwaniaDzwieku); //ais
    if(klawisz == 'o')Beep(554,czasTrwaniaDzwieku); //cis
    if(klawisz == 'p')Beep(622,czasTrwaniaDzwieku); //dis
    if(klawisz == ']')Beep(740,czasTrwaniaDzwieku); //fis
}
void odczyt()
{
    int czasOdstepu;
    int pusty;
    system("cls");
    printf("MENU: \n1. Tryb wolny\n2. Nagrywaj\n3. Posluchaj\n4. Odtworz ostatnie nagranie<--\n5. Wyjdz z programu\n\n");
    pianino();
    FILE *fzapis;
    if((fzapis = fopen("zapis.txt", "r"))!=NULL);
        else
        {
            printf("Brak pliku 'zapis.txt'");
            Sleep(1000);
            rozpoczecie();
        }
fseek(fzapis, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(fzapis);
    printf("\nOdtwarzanie nagrania\n");
    if (len > 0) //sprawdza czy plik jest pusty
    {
        rewind(fzapis);
        while(!feof(fzapis))
        {
            fscanf(fzapis,"%c\n",&klawisz); //odczytuje pliku
            dzwiek();
            fscanf(fzapis,"%d\n",&czasOdstepu);
            Sleep(czasOdstepu);
        }
    }
    else
    {
        printf("Nic nie nagrales!\n");
        Sleep(1000);
    }
    rozpoczecie();
}
void posluchaj()
{
    int czasOdstepu;
    system("cls");
    printf("MENU: \n1. Tryb wolny\n2. Nagrywaj\n3. Posluchaj<--\n4. Odtworz ostatnie nagranie\n5. Wyjdz z programu\n\n");
    pianino();
    printf("\nSluchaj...");
    FILE *fmuzyka;
    if((fmuzyka = fopen("sto_lat.txt", "r"))!=NULL);
    else
    {
        printf("Brak pliku:'sto_lat.txt'");
        Sleep(1000);
        rozpoczecie();
    }
    while(!feof(fmuzyka))
    {
        fscanf(fmuzyka,"%c\n",&klawisz);
        dzwiek();
        fscanf(fmuzyka,"%d\n",&czasOdstepu);
        Sleep(czasOdstepu);
    }
    rozpoczecie();
}
int main()
{
rozpoczecie();

return 0;
}
