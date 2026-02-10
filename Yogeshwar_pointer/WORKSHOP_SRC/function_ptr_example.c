void sort1(int* pa, int N){
    int i, j; 
    int key; 

    for(j = 1; j < N; ++j){
        key = pa[j]; 
        i = j - 1; 
        while(i > -1 && pa[i] > key){
            pa[i+1] = pa[i]; 
            i = i - 1; 
        }
        pa[i+1] = key; 
    }
}

struct student{
    int st_roll; 
    int st_marks; 
    float st_attnd; 
}; 

void sort2(struct student* pSt, int N, int (*compare)(struct student*, struct student*)){
    int i, j; 
    int ret = compare(pSt+i, pSt+j);
    // ret > 0 
    // pst[i] > pst[j] 
}

int compare_1(struct student* p1, struct student* p2){
    if(p1->st_roll > p2->st_roll)
        return (1); 
    else if(p1->st_roll < p2->st_roll)
        return (-1); 
    else 
        return (0); 
}

sort2(student_arr, N, compare_1); 

void sort(void* a, size_t N, size_t nmem, int (*pfn_compare)(const void*, const void*)){

}