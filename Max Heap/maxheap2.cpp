
class Heap{
    vector<int> arr;
    int size;
    
    void heapifyUp(int index){
        while(index > 1 && arr[index] > arr[index/2]){
            swap(arr[index], arr[index/2]);
            index /= 2;
        }
    }
    
    void heapifyDown(int index){
        int largest = index;
        int left = 2*index;
        int right = 2*index + 1;
        
        if(left <= size && arr[left] > arr[largest])
            largest = left;
        
        if(right <= size && arr[right] > arr[largest])
            largest = right;
        
        if(largest != index){
            swap(arr[index], arr[largest]);
            heapifyDown(largest);
        }
    }
    
public:
    Heap(int capacity = 16){
        arr.resize(capacity + 1); 
        size = 0;
        arr[0] = -1; 
    }
    
    void push(int data){
        if(size == arr.size() - 1) 
            arr.resize(arr.size() * 2); 
        
        arr[++size] = data; 
        heapifyUp(size); 
    }
    
    int pop(){
        if(isEmpty())
            throw std::runtime_error("Heap is empty");
        
        int popped = arr[1];
        arr[1] = arr[size--]; 
        heapifyDown(1); 
        
        if(size == arr.size() / 4) 
            arr.resize(arr.size() / 2);
        
        return popped;
    }
    
    bool isEmpty(){
        return size == 0;
    }
};