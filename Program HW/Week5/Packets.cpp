#include <bits/stdc++.h>
using namespace std;
int main()
{
    int box[6],result,lea,leb;
    while (cin >> box[0] >> box[1] >> box[2] >> box[3] >>box[4]>>box[5])
    {
        if ((box[0]==0)&&(box[1]==0)&&(box[2]==0)&&(box[3]==0)&&(box[4]==0)&&(box[5]==0))
            break;
        result=box[5];
        result+=box[4];
        lea=box[4]*11;
        if (box[0] <= lea) box[0]=0;
        else  box[0]-=lea;
        result+=box[3];
        lea=box[3]*20;
        if (box[1]*4 <= lea)
        {
            lea-=box[1]*4;
            box[1]=0;
        }
        else
        {
            box[1]-=lea/4;
            lea=0;
        }
        if (box[0] <= lea)
        {
            lea-=box[0];
            box[0]=0;
        }
        else
        {
            box[0]-=lea;
            lea=0;
        }
        result+=box[2]/4;   //處理3x3
        box[2]=box[2]%4;        //處理3x3後不足1個給2x2
        if (box[2] > 0) result++;
        if (box[2] == 1)
        {
            if(box[1] >= 5)
            {
                box[1]-=5;
                lea=7;
            }
            else
            {
                lea=27-box[1]*4;
                box[1]=0;
            }
        }
        if (box[2] == 2)
        {
            if(box[1] >= 3)
            {
                box[1]-=3;
                lea=6;
            }
            else
            {
                lea=18-box[1]*4;
                box[1]=0;
            }
        }
        if (box[2] == 3)
        {
            if(box[1] >= 1)
            {
                box[1]-=1;
                lea=5;
            }
            else
            {
                lea=27;
            }
        }
        if (box[0] <= lea)
        {
            lea-=box[0];
            box[0]=0;
        }
        else
        {
            box[0]-=lea;
            lea=0;
        }
        result+=box[1]/9;
        box[1]=box[1]%9;
        if (box[1] > 0)
        {
            result++;
            lea=36-box[1]*4;
        }
        if (box[0] <= lea)
        {
            box[0]=0;
        }
        else
        {
            box[0]-=lea;
            lea=0;
        }
        result+=box[0]/36;   //處理1x1
        if ((box[0]%36) >0) result ++;
        cout << result << endl;
    }
    return 0;
}
