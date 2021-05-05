//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k);
void swap(char &a,char &b);
void unwantedChar1(string& str);
string decryptBinary(string str, int strsize);
string decryptIntoChar(string str, int strsize);
string treatingInputWithVUA(string str, int strsize);
void quickSortWithString(string& str, int start, int end);
void treatingInputWithTHD(string& str, int strsize);
int gcdFind(int p, int q);
void jugglingRot(string& str,int strsize,int dist);
string ordinate(string str, int N);
int countV(string str);
int modulos( long long int a,  int b);
void stringProcessing(string str,  long long int** result);
void specialMatrixMultiply( long long int** mat1,  long long int** mat2,  long long int** result, int V, int n);
//just to avoid warning -Wmissing declaration

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////


void swap(char &a,char &b){
    char temp;
    temp=a;
    a=b;
    b=temp;
}

void unwantedChar1(string& str){
    for (unsigned int  i = 0; i<str.length(); ++i){
        if (str[i]=='#' || str[i]=='@' || str[i]=='*'){
            str.erase(str.begin()+i);
            --i;
        }
    }
}

string decryptBinary(string str, int strsize){
    string empty = "";
    int i = 0;
    while (i<strsize){
        if (str[i]==' '){
            ++i;
            empty += " ";
            continue;
        }
        else if (str[i]=='0'){
            ++i;
            if (str[i]=='0') empty += "0";
            else if (str[i]=='1') empty +="1";
            ++i;
        }
        else if(str[i]=='1'){
            ++i;
            if (str[i]=='0') empty += "2";
            else if (str[i]=='1') empty +="3";
            ++i;
        }
    }
    return empty;
}

string decryptIntoChar(string str, int strsize){
    string lookuptab[4][7] = {{"E","F","G","H","I","J","K"},
                              {"L","M","N","O","P","Q","R"},
                              {"#","T","U","V","W","X","Y"},
                              {"@","A","S","Z","B","C","D"}};
    string empty = "";
    int count = 0,i=0;
    char temp;
    while (i<strsize){
        if (str[i]>=48 && str[i]<=51){
            if (i==strsize-1 && str[strsize-2]==str[strsize-1]){
                ++i;
                continue;
            }
            else if (i==strsize-1 && str[strsize-2]!=str[strsize-1]){
                temp = str[i];
                empty += lookuptab[temp-48][0];
                ++i; continue;
            }
            else {
                temp = str[i]; count = 1;
                while (i<strsize-1 && str[++i]==temp){
                    ++count;
                }
                if (count>7){
                    if (count%7==0) count = 7;
                    else count=count%7;
                }
                empty += lookuptab[temp-48][count-1];
                if (temp == '2' && count==1){
                    empty += '*';
                }
            }
        }
        else ++i;
    }

    int newsize=empty.length();

    for (int  j = 0; j<newsize; ++j){
        if (empty[j]=='*'){
            int idx = j+1;
            while (idx<newsize){
                if (empty[idx]=='#' || empty[idx]=='@') break;
                idx++;
            }
            if (idx>j+1){
                int iter = j;
                while (iter<idx){
                    if (iter==idx-1){
                        if (empty[iter]=='Z') empty[iter] = 'A';
                        else empty[iter]=empty[iter-1]+1;
                    }
                    else empty[iter]=empty[iter+1];
                    ++iter;
                }
            }
        }
    }

    for (int  x = 0; x<newsize; ++x){
        if (empty[x]=='@'){
            int checkidx = x+1;
            while (checkidx<newsize){
                if (empty[checkidx]=='#' || empty[checkidx]=='@') break;
                checkidx++;
            }
            int temp1 = checkidx-1;
            checkidx-=1;
            for (int x1 = x+1; x1 < checkidx; ++x1){
                swap(empty[x1], empty[checkidx]);
                checkidx-=1;
            }
            x=temp1;
        }
    }
    return empty;
}

string treatingInputWithVUA(string str, int strsize){
    string newstring= "";
    if (strsize%2==1){
        for (int i  = strsize-1; i>=0; --i){
            newstring += str[i];
        }
    }
    else{
        for (int i = strsize-2; i>=0; i-=2){
            newstring+=str[i];
            newstring+=" ";
        }
        for (int i = 1; i<strsize; i+=2){
            newstring[i]=str[strsize-i];
        }
    }
    for (int i = 0; i<strsize; ++i){
        if (newstring[i]<str[i]){
            newstring[i]=str[i];
        }
    }
    return newstring;
}

void quickSortWithString(string& str, int start, int end){
  if (start<end){
    int piv = str[start]; int nextpos = start;
    for (int i = start+1; i<=end; ++i){
        if (str[i]<piv){
          ++nextpos;
          swap(str[nextpos],str[i]);
        }
    }
    swap(str[nextpos],str[start]);
    quickSortWithString(str,start,nextpos-1);
    quickSortWithString(str,nextpos+1,end);
  }
}
void treatingInputWithTHD(string& str, int strsize){
    for (unsigned int  i = 3; i<str.length(); i+=2){
        str.erase(str.begin()+i);
    }
    str.erase(0,1);
    strsize=str.length();
    quickSortWithString(str,0,strsize-1);
}

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1){
    int vua2tuong1quan0 = 0;
    for (int j = 0;j<NID; ++j){
        size_t tuong = ID[j].find("THD");
        size_t vua = ID[j].find("VUA");
        unsigned int dodai = ID[j].length();
        dodai-=3;
        unsigned int firstpos = 0;

        if (vua!=string::npos && vua==firstpos){
            vua2tuong1quan0 = 2;
            break;
        }
        if (tuong!=string::npos && tuong>firstpos && tuong<dodai){
            vua2tuong1quan0 = 1;
            break;
        }
    }

    string trave = "";
    int strsize = 0;
    for (int i = 0; i<N1; ++i){
        string dupli = input1[i];

        strsize = dupli.length();
        dupli=decryptBinary(dupli,strsize);

        strsize = dupli.length();
        dupli=decryptIntoChar(dupli,strsize);

        strsize = dupli.length();
        unwantedChar1(dupli);

        strsize = dupli.length();

        if (vua2tuong1quan0==1){
            treatingInputWithTHD(dupli,strsize);
        }
        else if (vua2tuong1quan0==2){
            dupli=treatingInputWithVUA(dupli,strsize);
        }

        trave += dupli;
        if (i!=N1-1) trave += " ";
    }
    return trave;
}


int decode(const string str, const string pattern){
    size_t curr = str.find(pattern,0);
    int ret = 0;
    while(curr!= string::npos){
        ++ret;
        curr = str.find(pattern,curr+1);
    }
    return ret;
}


int gcdFind(int p, int q){
    int ret = 1;

    for (int i = q; i>1; --i){
        if (p%i==0 && q%i==0){
            ret = i;
            break;
        }
    }
    return ret;
}
void jugglingRot(string& str,int strsize,int dist){
    if (dist==strsize) return;

    int num_group = gcdFind(dist,strsize);

    for(int j = 0; j < num_group; j++){
	int next=j+dist;
        while (next!=j){
            int temp=str[j];
	    str[j]=str[next];
	    str[next]=temp;
            next+=dist;
            if(next>=strsize){
                next=next-strsize;
            }
        }
    }
}
string ordinate(string str, int N){
    char uu[4] = {'U','D','L','R'};
    char dd[4] = {'D','L','R','U'};
    char ll[4] = {'L','R','U','D'};
    char rr[4] = {'R','U','D','L'};
    string ret = "(";
    int len = str.length(); int det = 0;
    int x=0; int y=0;

    for (int i = 0; i<len; ++i){
        det = abs(N-2*i);
        det = det%4;
        if (str[i]=='U') str[i]=uu[det];
        else if (str[i]=='D') str[i]=dd[det];
        else if (str[i]=='L') str[i]=ll[det];
        else str[i]=rr[det];
    }
    for (int i = 0; i<len; ++i){
        if (str[i]=='U') ++y;
        else if (str[i]=='D') --y;
        else if (str[i]=='L') --x;
        else ++x;
    }
    ret=ret+to_string(x)+","+to_string(y)+")";
    return ret;
}
string findRoute(const string input3){

    int input3len = input3.length();
    int count = 0; int prev = 0;
    int N=0,B=0; string S;

    for (int i = 0; i<input3len; ++i){
        if (input3[i]==' '){
            ++count;
            if(count==1){
                N=stoi(input3.substr(0,i));
                prev = i+1;
            }
            else if(count==2){
                B=stoi(input3.substr(prev,i-prev));
                prev = i+1;
                S=input3.substr(prev,input3len-prev);
                break;
            }
        }
    }

    int lenS = S.length();
    if (B<0){
        B=abs(B);
        if (B>lenS) B=B%lenS;
        jugglingRot(S,lenS,lenS-B);
    }
    else if (B>0){
        if (B>lenS) B=B%lenS;
        jugglingRot(S,lenS,B);
    }
    return ordinate(S,N);;
}



int countV(string str){
    int strsize = str.length(),count=0;
    for(int i = 0; i<strsize; ++i){
        if (str[i]=='V') ++count;
    }
    return count;
}
string decodeVfunction(const string str1, const string str2){
    string ketqua="";
    int num_of_iter=countV(str1)*countV(str2);
    for (int i = 0; i<num_of_iter; ++i){
        ketqua += "V(";
    }
    ketqua += "0";
    for (int i = 0; i<num_of_iter; ++i){
        ketqua += ")";
    }
    return ketqua;
}


string findBetrayals(const string input5[], const int N5){
    int traitors[26] = {};
    int point = 0;
    int maxIDX=0;
    int maxpoint=0;
    string treasons = "";

    for (int i = 0; i<N5; ++i){
        for (int j=0; j<6; ++j){
            point = 6-j;
            traitors[(int)input5[i][j]-65]+=point;
        }
    }

    for (int i = 0; i<3; ++i){
        maxpoint = 0;
        for (int j = 0; j<26; ++j){
            if (traitors[j]>maxpoint){
                maxpoint=traitors[j];
                maxIDX = j;
            }
        }
        char betrayal = maxIDX+65;
        treasons=treasons+betrayal;
        traitors[maxIDX]=-1;
    }

    return treasons;
}


int attack(const string input6[]){
    int weakness[10] = {};
    int minp=11; int minrow=0; int ret = -1;

    for(int i=0; i<10; ++i){
        for(unsigned int j =0; j<input6[i].length();++j){
            if(input6[i][j]=='1')
                weakness[i]+=1;
            else if(input6[i][j]=='2'){
                weakness[i]=99;
                continue;
            }
        }
    }

    for (int i=9; i>=0;--i){
        if (weakness[i]<minp){
            minp= weakness[i];
            minrow=i;
        }
    }
    if (minp!=11) ret=minrow;
    return ret;
}



//get the right mod

int modulos( long long int a,  int b){
  return (int)(((a % b) + b) % b);
}


//For the square matrix only
void stringProcessing(string str,  long long int** result){
	int strsize = str.size(); int num_el = 0,temp=0;
	int mat_size=0;

	for (int i = 0;i<strsize;++i){
		if (str[i]==' ') ++num_el;
	}
	
	++num_el; mat_size = sqrt(num_el);
	
	string* string_arr = new string[num_el];

	for (int i = 0;i<strsize;++i){
		if (str[i]==' ')  ++temp;
		else if (str[i]!=' '){
		    string_arr[temp]+=str[i];
		}
	}
	
	for (int i = 0; i<num_el;++i){
		result[i/mat_size][i%mat_size] = stoll(string_arr[i]);
	}
	
	delete[] string_arr;
	
}


void specialMatrixMultiply( long long int** mat1,  long long int** mat2,  long long int** result, int V, int n){
	int i,j,k;
	
	for (i = 0; i < n;++i){
		for (j = 0; j < n;++j){
			for (k = 0; k < n;++k){
				result[i][j] += (mat1[i][k]%V)*(mat2[k][j]%V);
			}
		}
	}
}


int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k){
	int strsize = input7Str.size();
	string input_stored[4];
	int iter1=0,start=0;  int ret=0;
	int N7=0,V=0,index1=0,index2=0;
	
	for (int i = 0; i<strsize;++i){
		if (input7Str[i]==' '){
		    input_stored[iter1]=input7Str.substr(start,i-start);
		    ++iter1;
		    start=i+1;
	    }
	    if (iter1==3){
	        input_stored[iter1]=input7Str.substr(start,strsize-start);
	    }
	}
	
	N7 = stoi(input_stored[0]);
	V = stoi(input_stored[1]);
	index1 = stoi(input_stored[2]);
	index2 = stoi(input_stored[3]);
	
	if (N7==0) return 0;
	
	 long long int** mat1 = new  long long int* [N7];
	for (int i = 0; i < N7;++i){
	    mat1[i] = new  long long int[N7];
	} 
	
	 long long int** mat2 = new  long long int* [N7];
	for (int i = 0; i < N7;++i){ 
	    mat2[i] = new  long long int[N7];
	}
	
	 long long int** mat3 = new  long long int* [N7]; 
	for (int i = 0; i < N7;++i){ 
	    mat3[i] = new  long long int[N7];
	}
	
	stringProcessing(input7Matrix[0],mat1);	

	for (int i = 1; i<k;++i) {
		stringProcessing(input7Matrix[i],mat2); 
		specialMatrixMultiply(mat1,mat2,mat3,V,N7); 
		for (int x=0;x<N7;++x){
		    for(int j=0;j<N7;++j){
		        mat1[x][j]=mat3[x][j];
		        mat3[x][j]=0;
		    }
		}
	}
	
	ret = modulos(mat1[index1][index2],V); //CO the se chua lai.
	
	
	for (int i = 0; i < N7;++i){ 
	    delete[] mat1[i];
	}
	delete[] mat1;
	
	for (int i = 0; i < N7;++i){
	    delete[] mat2[i];
	} 
	delete[] mat2;
	
	for (int i = 0; i < N7;++i){ 
	    delete[] mat3[i];
	}
	delete[] mat3;
	
	return ret;
}
//not sure 100% the task 7 but that's what i can do.

#endif /* MONGOL_H */
