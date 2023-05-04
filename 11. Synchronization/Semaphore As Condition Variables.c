sem_t s;
void * child (void *args){
    printf("child\n");
    sem_post(&s);
    return NULL;
}

int main(int argc, char *argvp[]){
    // initial value of this semaphore = 0 (last part)
    sem_init(&s, 0, 0);
    // Semaphores are used both for 1) Mutual exclusion 2) Condition synchronization
    printf("parent: begin\n");
    pthread_t c;
    pthread_create(c, NULL, child, NULL);
    sem_wait(&s);
    printf("parent: end\n");
    return 0;
}