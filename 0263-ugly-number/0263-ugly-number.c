bool isUgly(int n) {
    int i;
    if(n<=0){
        return false;
    }
    for (i=0;n%2==0;i++){
        n=n/2;
    }
    for (i=0 ; n%3==0;i++){
        n=n/3;
    }
    for (i=0;n%5==0;i++){
        n=n/5;
    }
    if (n==1){
        return true;
    }
    return false;
}