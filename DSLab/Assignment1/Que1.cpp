#include <iostream>

int main() {
    int arr[100];
    int size = 0;
    int choice;

    while (true) {
        std::cout << "\n--- MENU ---" << std::endl;
        std::cout << "1. CREATE" << std::endl;
        std::cout << "2. DISPLAY" << std::endl;
        std::cout << "3. INSERT" << std::endl;
        std::cout << "4. DELETE" << std::endl;
        std::cout << "5. LINEAR SEARCH" << std::endl;
        std::cout << "6. EXIT" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Enter number of elements: ";
                std::cin >> size;
                std::cout << "Enter " << size << " elements: ";
                for (int i = 0; i < size; i++) {
                    std::cin >> arr[i];
                }
                break;
            }

            case 2: {
                if (size == 0) {
                    std::cout << "Array is empty" << std::endl;
                } 
                else {
                    std::cout << "Array elements: ";
                    for (int i = 0; i < size; i++) {
                        std::cout << arr[i] << " ";
                    }
                    std::cout << std::endl;
                }
                break;
            }

            case 3: {
                if (size >= 100) {
                    std::cout << "Array is full, cannot insert" << std::endl;
                } 
                else {
                    int pos, val;
                    std::cout << "Enter position to insert (0 to " << size << "): ";
                    std::cin >> pos;
                    if ((pos < 0) || (pos > size)) {
                        std::cout << "Invalid position" << std::endl;
                    } 
                    else {
                        std::cout << "Enter value to insert: ";
                        std::cin >> val;
                        for (int i = size; i > pos; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[pos] = val;
                        size++;
                        std::cout << "Element inserted successfully" << std::endl;
                    }
                }
                break;
            }

            case 4: {
                if (size == 0) {
                    std::cout << "Array is empty, cannot delete" << std::endl;
                } 
                else {
                    int pos;
                    std::cout << "Enter position to delete (0 to " << size - 1 << "): ";
                    std::cin >> pos;
                    if ((pos < 0) || (pos >= size)) {
                        std::cout << "Invalid position" << std::endl;
                    } 
                    else {
                        for (int i = pos; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        std::cout << "Element deleted successfully" << std::endl;
                    }
                }
                break;
            }

            case 5: {
                if (size == 0) {
                    std::cout << "Array is empty" << std::endl;
                } 
                else {
                    int key, found = 0;
                    std::cout << "Enter element to search: ";
                    std::cin >> key;
                    for (int i = 0; i < size; i++) {
                        if (arr[i] == key) {
                            std::cout << "Element found at position " << i << std::endl;
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0) {
                        std::cout << "Element not found" << std::endl;
                    }
                }
                break;
            }

            case 6: {
                std::cout << "Exiting program..." << std::endl;
                return 0;
            }

            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0;
}
                    
