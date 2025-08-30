#include<iostream>
#include<algorithm> // For std::swap

using namespace std;

class Heap{ // for max-heap, can be modified for min-heap
public:
    int arr[100]; 
    int size;

    Heap(){
        arr[0] = -1; // Sentinel node for 1-based indexing
        size = 0;
    }

    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index / 2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    // --- CORRECTED METHOD ---
    void deleteFromHeap(){
        if(size == 0){
            cout << "Heap is empty" << endl;
            return;
        }

        // Step 1: Put the last element into the root position
        arr[1] = arr[size];

        // Step 2: "Remove" the last element by decrementing size
        size--;

        // Step 3: Heapify down from the root (index 1)
        int i = 1;
        while(i <= size){ // Loop until we've checked all relevant nodes
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            int largest = i;

            // Find the largest among the node and its children
            if(leftChild <= size && arr[leftChild] > arr[largest]){
                largest = leftChild;
            }
            if(rightChild <= size && arr[rightChild] > arr[largest]){
                largest = rightChild;
            }

            // If the current node is not the largest, swap it with the largest child
            if(largest != i){
                swap(arr[i], arr[largest]);
                i = largest; // Move down to the swapped child's position
            }
            else{
                // The heap property is satisfied, so we can stop
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right <= n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // --- CORRECTED METHOD ---
    void printHeap(){
        // The loop must go up to and including the size
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap after insertions: ";
    h.printHeap(); // Expected: 55 54 53 50 52

    h.deleteFromHeap(); // Deletes 55
    cout << "Heap after deletion: ";
    h.printHeap(); // Expected: 54 52 53 50


    // Heapify example
    int arr[6] = {-1, 54, 53, 55, 52, 50}; // -1 is a placeholder for 1-based indexing
    int n = 5;
    for(int i = n / 2; i > 0; i--){
        h.heapify(arr, n, i);
    }
    cout << "Array after heapify: ";
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}