#ifndef firstFight_h
#define firstFight_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
void handle_(int& M, int& HP){
    if (M>1000) M=1000;
    else if (M<0) M=0;
    if (HP>1000) HP=1000;
    else if (HP<0) HP=0;
}
int digit_prime(int x){
    int temp = x%10;
    if (temp==2 || temp == 3|| temp==5 || temp==7){
        return 1;
    }
    return 0;
}
int getReady(int& HP, const int& ID, int& M, const int& E1){
    if (E1<100 || E1>500) return -999;
    handle_(M,HP);
    if (E1>=100 && E1<=199){
        if (ID==1){
            HP+=75;
        }
        else if (ID==0){
            int h = (E1-100)%64;
            int J = HP%100;
            if (J>h){
                if (HP>=500 && M%2!=0 && M>=300){
                    HP+=50;
                    M-=300;
                }
                else if(M%2==0 && M>=200){
                    HP+=25;
                    M-=200;
                }
            }
        }
    }
    else if (E1>=200 && E1<=299){
        int MG[5] = {0,190,195,200,205};
        int MGHP[5] = {0,5,7,9,11};
        int x = E1%4+1;
        if (ID!=0 && M>=MG[x] ){
            HP+= MGHP[x];
            M-= MG[x];
        }
        else if (ID==0){
            if (M%2!=0){
                if (MG[x]%2==0 && M>=MG[x]){
                    HP += MGHP[x];
                    M -= MG[x];
                }
            }
            else{
                if(MG[x]%2!=0 && M>=MG[x]){
                    HP+=MGHP[x];
                    M-=MG[x];
                }
            }    
        }
    }
    else if (E1>=300 && E1<=399){
        if ( HP<600 ){
            return HP+M;
        }
        int temp3=E1%10; int a = 1;
        if (digit_prime(E1)==1){
            a=2*temp3;
        }
        if ( digit_prime(HP)==1 && M>=500 ){
            if (ID==1){
                HP+=200;
            }
            else HP = ceil(HP+(2*a*0.01f*HP));
            M-=500;
        }
        else if ( digit_prime(HP)!=1 && M >= 300){
            HP = ceil(HP+(a*0.01f*HP));
            M-=300;
        }
    }
    else if (E1>=400 && E1<=499){
        if (E1%5==0){
            HP = ceil(HP*0.9f);
        }
    }
    else if (E1==500){
        return ceil((M+HP)*(0.75f));
    }
    handle_(M,HP);
    return HP+M;
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
    if (E2<100 || E2>499) return -999;
    else if (E2>=100 && E2<=199){
        HP1 = ceil(HP1*1.1f);
        HP2 = ceil(HP2*1.3f);
        handle_(HP1,HP2);
    }
    else if (E2>=200 && E2<=299){
        HP1 = ceil(HP1*1.7f);
        HP2 = ceil(HP2*1.2f);
        handle_(HP1,HP2);
    }
    else if (E2>=300 && E2<=399){
        if  (E2<350){
            HP1 += 30;
        }
        else HP1 = HP1 + (E2%100);
        handle_(HP1,HP2);
    }
    else if (E2>=400 && E2<=499){
        HP1 = ceil(HP1*1.3f);
        HP2 = ceil(HP2*0.8f);
        handle_(HP1,HP2);
        HP1 = ceil((float)HP1/2);
    }
    int ret=0;
    if (ID1 != 0 && ID2 == 0){
        HP2=0;
        ret = 1;
    } 
    else if (ID1 == 0 && ID2!=0){
        HP1=0;
        ret = -1;
    } 
    else if (ID1!=0 && ID2!=0){
        ret = 0;
    }
    else if (ID1==0 && ID2==0){
        int avg = ceil((2.0f*HP1*HP2)/(HP1+HP2));
        int tempHP1=HP1;
        HP1 = HP1 - abs(HP2-avg);
        HP2 = HP2 - abs(tempHP1-avg);
        if (HP1 > HP2) ret = 1;
        else if (HP1 < HP2) ret = -1;
        else if (HP1 == HP2) ret=0;
        handle_(HP1,HP2);                     //chuyen handle_ xuong sau khi xet thang thua
    }
    HP1 = ceil(HP1*0.8f);
    return ret;
}


int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    if (E3<100 || E3>299) return -999;
    int ret2 = 0;
    HP1 = ceil(1.4f*HP1);
    HP2 = ceil(1.6f*HP2);
    handle_(HP1,HP2);
    if (ID1==1){
        HP1*=2;
        handle_(HP1,HP2);
    }
    if (ID2==0){
        HP2 = ceil(0.95f*HP2);
    }
    if (E3>=100 && E3<=199){
        if (ID1 != 0 && ID2 == 0){
            HP2=0;
            ret2 = 1;
        } 
        else if (ID1 == 0 && ID2!=0){
            ret2 = -1;
        } 
        else if (ID1!=0 && ID2!=0){
            ret2 = 0;
        }
        else if (ID1==0 && ID2==0){
            int avg2 = ceil((2.0f*HP1*HP2)/(HP1+HP2));
            int tempHP1=HP1;
            HP1 = HP1 - abs(HP2-avg2);
            HP2 = HP2 - abs(tempHP1-avg2);
            handle_(HP1,HP2);
            if (HP1 > HP2) ret2 = 1;
            else if (HP1 < HP2){
                ret2 = -1;
                HP1 = tempHP1;
            }
        }
    }
    return ret2;
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    if (E4<100 || E4>299) return -999;
    handle_(HP1,HP2); int ret3=0;
    if (E4>=100 && E4<=199){
        if (ID2==0){
            HP2 = ceil(0.1f*HP2);
        }
        else HP2 = ceil(0.3f*HP2);
    }
    else if (E4>=200 && E4<=299){
        HP2=0;
        ret3=1;
    }
    return ret3;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */
