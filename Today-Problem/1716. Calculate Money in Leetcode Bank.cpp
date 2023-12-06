int totalMoney(int n) {
     int count=0;
     for(int i=0;i<n;i++){
         count+=(i/7)+1+(i%7);
     }   
     return count;
    }