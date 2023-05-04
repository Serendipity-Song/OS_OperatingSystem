// [Producer]

void producer(){
    while(1){
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE)
            pthread_cond_wait(&empty, &mutex);
        put(value);
        pthread_cond_signal(&fill);
        pthread_mutex_unlock(&mutex);
    }
}

// [Consumer]

void consumer() {
    while(1){
        pthread_mutex_lock(&mutex);
        while (count == 0)
            pthread_cond_wait(&fill, &mutex);
        take();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        consume();
    }
}