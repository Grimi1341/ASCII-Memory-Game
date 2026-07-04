#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;

void rubash(int num_karti){
    int shet = 1;
    for (int i = 0; i < num_karti; i++) {
        for (int j = 0; j < num_karti; j++) {
            cout<<" ______  ";
        }
        cout<<"\n";
        for (int j = 0; j < num_karti; j++) {
            cout<<"|      | ";
        }
        cout<<"\n";
        for (int j = 0; j < num_karti; j++) {
            if(shet<10){cout<<"|  0"<<shet<<"  | ";}
            else{cout<<"|  "<<shet<<"  | ";}
            shet++;
        }
        cout<<"\n";
        for (int j = 0; j < num_karti; j++) {
            cout<<"|      | ";
        }
        cout<<"\n";
        for (int j = 0; j < num_karti; j++) {
            cout<<" ‾‾‾‾‾‾  ";
        }
        cout<<"\n";
    }
    Sleep(300);
}
void proverka1(int karti1){
    switch (karti1){
        case 0: cout<<"        ";
        break;
        case 1: cout<<"|", printf("\033[30;43m"), cout<<"() () " ;
        break;
        case 2: cout<<"|", printf("\033[37;41m"), cout<<"()_() ";
        break;
        case 3: cout<<"|", printf("\033[37;42m"), cout<<R"(/\_/\ )";
        break;
        case 4: cout<<"|", printf("\033[33;44m"), cout<<" ____ ";
        break;
        case 5: cout<<"|", printf("\033[37;45m"), cout<<" ʘ__ʘ ";
        break;
        case 6: cout<<"|", printf("\033[30;46m"), cout<<"(^_-) ";
        break;
        case 7: cout<<"|", printf("\033[30;47m"), cout<<"(V_V) ";
        break;
        case 8: cout<<"|", printf("\033[32;40m"), cout<<"(o.o) ";
        break;
    }
}
void proverka2(int karti1){
    switch (karti1){
        case 0: cout<<"  empty  ";
        break;
        case 1: cout<<"|", printf("\033[30;43m"), cout<<"(•.• )" ;
        break;
        case 2: cout<<"|", printf("\033[37;41m"), cout<<"(o.o )";
        break;
        case 3: cout<<"|", printf("\033[37;42m"), cout<<"(-.•) ";
        break;
        case 4: cout<<"|", printf("\033[33;44m"), cout<<"_(__)_";
        break;
        case 5: cout<<"|", printf("\033[37;45m"), cout<<"( ⚆_⚆)";
        break;
        case 6: cout<<"|", printf("\033[30;46m"), cout<<"~[ ]~ ";
        break;
        case 7: cout<<"|", printf("\033[30;47m"), cout<<R"( / _ \)";
        break;
        case 8: cout<<"|", printf("\033[32;40m"), cout<<R"(/|||\ )";
        break;
    }
}
void proverka3(int karti1){
    switch (karti1){
        case 0: cout<<"        ";
        break;
        case 1: cout<<"|", printf("\033[30;43m"), cout<<R"((")("))" ;
        break;
        case 2: cout<<"|", printf("\033[37;41m"), cout<<R"( " "  )";
        break;
        case 3: cout<<"|", printf("\033[37;42m"), cout<<R"(\_=_/ )";
        break;
        case 4: cout<<"|", printf("\033[33;44m"), cout<<"( •_•)";
        break;
        case 5: cout<<"|", printf("\033[37;45m"), cout<<R"( \_Д_/)";
        break;
        case 6: cout<<"|", printf("\033[30;46m"), cout<<R"( / \  )";
        break;
        case 7: cout<<"|", printf("\033[30;47m"), cout<<R"( " "  )";
        break;
        case 8: cout<<"|", printf("\033[32;40m"), cout<<R"(\|||/ )";
        break;
    }
}
int litso(int shet, int karti1, int otstup, bool right_ans){
    cout <<endl;
    cout << "\033[" << otstup << "C";
    if (karti1 != 0){
        cout<<" ______ ";
    } else {
        cout<<"        ";
    }
    cout <<endl;
    cout << "\033[" << otstup << "C";
    if (karti1 != 0){
        if (right_ans == false){
        cout<<"|      |";
        } else {
        proverka1(karti1);
        printf("\033[0m");
        cout<<"|";
        }
    } else {
        cout<<"         ";
    }
    cout <<endl;
    cout << "\033[" << otstup << "C";
    if (karti1 != 0){
        if (right_ans == false){
            if(shet>9){
                cout<<"|  "<<shet<<"  |";
            } else {
                cout<<"|  0"<<shet<<"  |";
            }
        } else {
            proverka2(karti1);
            printf("\033[0m");
            cout<<"|";
        }
    } else {
        cout<<"  empty  ";
    }
    shet++;
    cout <<endl;
    cout << "\033[" << otstup << "C";
    if (karti1 != 0){
        if (right_ans == false){
        cout<<"|      |";
        } else {
        proverka3(karti1);
        printf("\033[0m");
        cout<<"|";
        }
    } else {
        cout<<"         ";
    }
    cout <<endl;
    cout << "\033[" << otstup << "C";
    if (karti1 != 0){
        cout<<" ‾‾‾‾‾‾  ";
    } else {
        cout<<"         ";
    }
    cout << "\033[" << 5 << "A";
    return shet;
}
int main() {
    srand(time(NULL));
    int karti1[30][30], karti2[900], num_karti, num;
    int itog=0;
    int shet3 = 0;
    bool right_ans;
    //выбор режима
    cout<<"viberi rezhim:\n1 - 4 kartochki\n2 - 16 kartochek\n";
    cin>>num;
    if (num<4 && num>0){
       switch (num){
      case 1: num_karti = 2;
      break;
      case 2: num_karti = 4;
      break;}

      //рандомайзер чисел - задает карты

      for (int i = 0; i < num_karti*num_karti; i++) {
        int alpha = rand() % (num_karti*num_karti)/2 + 1, shet1=0;
        for (int k = 0; k < i; k++) {
            if(alpha==karti2[k]){shet1++;}
        }
        if(shet1<2){karti2[i]=alpha;}
        else{i--;}
      }
      int shet2=0;
      for (int i = 0; i < num_karti; i++) {
        for (int j = 0; j < num_karti; j++) {
            karti1[i][j] = karti2[shet2];
            shet2++;
        }
      }
      //выводим рубашки карт
      cout << "\033[2J\033[H" << flush;
        rubash(num_karti);
      //начинается игра
      while (itog!=num_karti*num_karti){
      int vibor1, vibor2, chek_kart1, chek_kart2, hod = 1;
      int i1, i2, j1, j2;
      int shet3 = 1;
        //игрок делает ход
        cout<<" viberite dve kartochki:\n (napechataite ih cherez probel)\n";
        cin>>vibor1>>vibor2;
        cout << "\033[2J\033[H" << flush;

        //игра выводит лица карт
        for (int i = 0; i < num_karti; i++) {
            int otstup = 1;
            for (int j = 0; j < num_karti; j++) {
                int num = num_karti * i + j + 1;
                int kart1 = karti1[i][j];
                bool right_ans = (num == vibor1 || num == vibor2);
                shet3 = litso(shet3, kart1, otstup, right_ans);
                Sleep(300);
                otstup = otstup + 9;
                if (num == vibor1){
                    chek_kart1 = karti1[i][j];
                    i1 = i, j1 = j;
                } else if (num == vibor2){
                    chek_kart2 = karti1[i][j];
                    i2 = i, j2 = j;
                }
            }
            cout<<"\n\n\n\n\n";
        } 
        cout<<"\n";
        //обнуление одинаковых карт 
        bool final_chek = (chek_kart1==chek_kart2 && vibor1-1!=vibor2-1) && (chek_kart1!=0 && chek_kart2!=0);
        if(final_chek == true){
            karti1[i1][j1] = 0;
            karti1[i2][j2] = 0;
            itog = itog + 2;
            cout<<"Ti ugadal"<<endl;
        } else if (chek_kart1 == 0 || chek_kart2 == 0) {
            cout<<"!!!!! Karta/i uzhe bila/i otgadana/i !!!!!";
        }
        Sleep(3000);
        cout << "\033[2J\033[H" << flush;
        //второй вывод рубашек карт

        int shet = 1;
    for (int i = 0; i < num_karti; i++) {
        cout<<"\n ";
        for (int j = 0; j < num_karti; j++) {
            if (karti1[i][j] == 0){
                cout<<"         ";
            } else {
                cout<<" ______  ";
            }
            
        }
        cout<<"\n ";
        for (int j = 0; j < num_karti; j++) {
            if (karti1[i][j] == 0){
                cout<<"         ";
            } else {
                cout<<"|      | ";
            }
        }
        cout<<"\n ";
        for (int j = 0; j < num_karti; j++) {
            if (karti1[i][j] == 0){
                cout<<"  empty  ";
            } else {
                if(shet<10){cout<<"|  0"<<shet<<"  | ";}
                else{cout<<"|  "<<shet<<"  | ";}
            }
            shet++;
        }
        cout<<"\n ";
        for (int j = 0; j < num_karti; j++) {
            if (karti1[i][j] == 0){
                cout<<"         ";
            } else {
                cout<<"|      | ";
            }
        }
        cout<<"\n ";
        for (int j = 0; j < num_karti; j++) {
            if (karti1[i][j] == 0){
                cout<<"         ";
            } else {
                cout<<" ‾‾‾‾‾‾  ";
            }
        }
        cout<<"\n ";
        Sleep(300);
    }
    hod++;

    if (final_chek == true){
        cout<<"Tebe ostalos ugadat: "<<num_karti*num_karti-itog<<" karti"<<endl;      
    } else {
        cout<<"Tebe ostalos ugadat: "<<num_karti*num_karti-itog<<" karti"<<endl;
    }

    if (itog == num_karti*num_karti){
        cout<<" GAME OVER! YOU WIN!\n Ti proshel igru za "<<hod<<" hodov";
    }
      }
    
    }
}
