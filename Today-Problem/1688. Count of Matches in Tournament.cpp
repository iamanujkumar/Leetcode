int numberOfMatches(int n) {
        int count=0;
    while(n!=1){
        int mtch=n/2;
        count+=mtch;
        n=n-mtch;
     }
     return count;
    }