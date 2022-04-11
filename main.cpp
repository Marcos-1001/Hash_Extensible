

using namespace std;



int main() {
    ext_hashing eh(4);
    for(int i  = 0 ; i<10; i++){
        eh.insert(i, i+1);
    }

    eh.display();
    return 0;
}
