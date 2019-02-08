#include <bits/stdc++.h>
using namespace std;

int cnt;

void recursive (int mask){
	printf("%s\n",a);
    char org [15];
    strcpy (org, a);

    for ( int i = 0; i < 11; i++ ) {
        if ( a [i] == 'o' && a [i + 1] == 'o' ) {
            if ( i + 2 < 12 && a [i + 2] == '-' ) {
                a [i + 2] = 'o';
                a [i] = a [i + 1] = '-';
                recursive (a);
                strcpy (a, org);
            }
            if ( i - 1 >= 0 && a [i - 1] == '-' ) {
                a [i - 1] = 'o';
                a [i] = a [i + 1] = '-';
                recursive (a);
                strcpy (a, org);
            }
        }
    }

    int c = 0;

    for ( int i = 0; i < 12; i++ ) {
        if ( a [i] == 'o' ) c++;
    }

    if ( c < cnt )
        cnt = c;
}

int main ()
{
	//freopen("out.txt","w",stdout);
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int mask = 0;
        char input [12 + 3];
        scanf ("%s", input);
        for(int i = 0; i < input.size(); i++){
            mask |= input[i] == '0'? 1<<i:0;
        }
        cnt = 100;
        print("%d\n",mask);
        recursive (input);

        printf ("%d\n", cnt);
    }

    return 0;
}
