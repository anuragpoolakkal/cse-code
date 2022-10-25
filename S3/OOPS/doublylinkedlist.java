public class Node{
	int data;
	Node next;
	Node prev;
}



import java.util.*;
class DoublyLinkedList{
	public static void main(String[] args){
		int arr[], int index =0,i,n;
		arr = new int[10];
		Scannner sc = new scanner(System.in)
		node current_node = null;
		node prev_node = null;
		node nxt_node = null;
		node start_node = null;
		node end_node = null;
		System.out.println("creating linked list \n");
		System.out.println("Enter number of nodes \n");
		n = nextInt();
		for(i =0; i<n; i++){
			System.out.println("Enter data")
			arr[i] = sc.next();
		}
		while(index < n){
			if(index> 0){
				prev_node.next = current_node;
			}else{
				start_node = current_node;
			}
			current_node.data = arr[index];
			current_node.next = null;
			current_node.prev = prev_node;
			index++;
			prev_node = current_node;
		}
		System.out.println("deleting node");
		System.out.print("Enter key");
		int key = sc.nextInt();
		current_node = start_node;
		if(start_node.data == key){
			start_node = start_node.next
		}
		else {

			while (current_node != null){
				prev_node = current_node.prev;
				nxt_node = current_node.next;
				prev_node = next_node;
				next_node.prev = previous_node
				System.out.println("node deleted");
				break;
			}
		}
		
		else {
	current_node = current_node.next;
	}

	}

	System.out.println("Displaying linked list");
	current_node = start_node;
	while (current_node != null) {
		System.out.println(current_node.data);
		current_node = current_node.next;
		}
	}
}
