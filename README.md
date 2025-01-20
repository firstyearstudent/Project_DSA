Giới thiệu:

Chương trình này thực hiện việc sắp xếp một danh sách liên kết (linked list) theo thứ tự tăng dần bằng cách sử dụng thuật toán Merge Sort. Người dùng có thể nhập số lượng phần tử và giá trị của các phần tử trong danh sách, sau đó chương trình sẽ sắp xếp danh sách và hiển thị kết quả.

![Screenshot 2025-01-20 102646](https://github.com/user-attachments/assets/f011b422-8b2e-42e9-b9bf-5eb25f3fd5b5)

Chức năng chính:

1. Nhập dữ liệu danh sách liên kết từ bàn phím:
 Người dùng cung cấp số lượng phần tử và giá trị của từng phần tử.

2. Sắp xếp danh sách liên kết:
 Sử dụng thuật toán Merge Sort để sắp xếp các phần tử trong danh sách theo thứ tự tăng dần.

3. In danh sách liên kết đã sắp xếp:
 Hiển thị danh sách liên kết sau khi sắp xếp.

Giải thuật: Merge Sort

 1. Ý tưởng chính:
  Merge Sort là thuật toán chia để trị (Divide and Conquer). Danh sách liên kết được chia thành hai phần nhỏ, các phần này được sắp xếp độc lập và sau đó hợp nhất lại thành danh sách đã sắp xếp.

 2. Các bước thực hiện
     - Nếu danh sách liên kết rỗng hoặc có một phần tử, trả về danh sách vì nó đã được sắp xếp.
     - Chia danh sách thành hai phần bằng nhau (sử dụng phương pháp con trỏ nhanh/chậm).
     - Gọi đệ quy Merge Sort cho từng phần.
     - Hợp nhất hai danh sách đã sắp xếp thành một danh sách mới.
 3. Độ phức tạp thời gian: O(nlog(n))

 4. Độ phức tạp không gian: O(log(n))

Mã giả:

FUNCTION mergeSort(head)

    IF head = NULL OR head.next = NULL THEN
        RETURN head

    // Chia danh sach thanh hai phan
    DECLARE front, back
    CALL splitList(head, front, back)

    // De quy sap xep hai phan
    front = mergeSort(front)
    back = mergeSort(back)

    // Hop nhat hai danh sach da sap xep
    RETURN mergeSortedLists(front, back)
END FUNCTION

FUNCTION splitList(source, frontRef, backRef)

    IF source = NULL OR source.next = NULL THEN
        frontRef = source
        backRef = NULL
        RETURN

    DECLARE slow, fast
    SET slow = source
    SET fast = source.next

    WHILE fast != NULL DO
        fast = fast.next
        IF fast != NULL THEN
            slow = slow.next
            fast = fast.next
        END IF
    END WHILE

    // Cat danh sach tai vi tri cua slow
    frontRef = source
    backRef = slow.next
    slow.next = NULL
END FUNCTION

FUNCTION mergeSortedLists(a, b)

    IF a = NULL THEN
        RETURN b
    IF b = NULL THEN
        RETURN a

    DECLARE result
    IF a.data <= b.data THEN
        result = a
        result.next = mergeSortedLists(a.next, b)
    ELSE
        result = b
        result.next = mergeSortedLists(a, b.next)
    END IF

    RETURN result
    
END FUNCTION

FUNCTION printList(head)

    WHILE head != NULL DO
        PRINT head.data, " → "
        head = head.next
    END WHILE
    PRINT "NULL"
    
END FUNCTION

FUNCTION append(headRef, data)

    CREATE newNode WITH data
    IF headRef = NULL THEN
        headRef = newNode
        RETURN

    DECLARE temp = headRef
    WHILE temp.next != NULL DO
        temp = temp.next
    END WHILE
    temp.next = newNode
    
END FUNCTION

MAIN

    DECLARE head = NULL
    INPUT n // So luong phan tu cua danh sach
    IF n <= 0 THEN
        PRINT "Danh sach lien ket phai co it nhat mot phan tu."
        EXIT

    FOR i FROM 1 TO n DO
        INPUT data // Gia tri cua tung phan tu
        CALL append(head, data)
    END FOR

    // Sap xep danh sach lien ket
    head = mergeSort(head)

    // In danh sach lien ket da sap xep
    PRINT "Danh sach lien ket da sap xep:"
    CALL printList(head)
    
END MAIN









 
