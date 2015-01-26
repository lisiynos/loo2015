int main()
{
    freopen("hall.in","r",stdin);
    freopen("hall.out","w",stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    c = c / 2 + c % 2;
    d /= 2;
    int s, p;
    unsigned long long cnt = 0;
    bool noErr = true;
    bool reached = false;
    int minByP, maxByP, minByS, maxByS, t;
    for (int e = 1; /*s <= d*/; e++){
        //reached = false;
        minByP = c - e;
        maxByP = d - e;
        minByS = a / e + ( (a % e) ? 1 : 0 );
        maxByS = b / e;
        t = min(maxByP, maxByS) - max(e, max(minByP, minByS) ) + 1;
        t = max(t,0);
        if (t) reached = true;
        cnt += t;
        if (reached && !(t))
            break;
        /*for (int f = max(e, c - e); ; f++){
            s = e * f;
            p = (e + f);
            if ( s >= a && p >= c){
                reached = true;
                if ( s <= b && p <= d){
                    ++cnt;
                    noErr = true;
                    //reached = true;
                } else if (reached) {
                    break;
                }
            }
        }
        if (reached)
            if (noErr)
                noErr = false;
            else
                break;*/
    }
    cout << cnt;
    return 0;
}