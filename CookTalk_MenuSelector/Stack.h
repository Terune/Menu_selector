#pragma once
template <typename Object>
class Stack
{
protected:
    // ����Ʈ�� ���
    //
    struct Node
    {
        Object obj;
        Node* next;
    };
    typedef Node* NodePtr;
 
public:
    Stack();
    virtual ~Stack();
 
    void push(const Object& o);
    void pop();
    Object& top();
    const Object top() const;
 
    int size() const;
    bool empty() const;
 
private:
    NodePtr top_;
    int size_;
};


// ������(): top_�� size_�� �ʱ�ȭ�Ѵ�.
//
template <typename Object>
Stack<Object>::Stack() : top_(NULL), size_(0) {}
 
// �Ҹ���(): ���� ���Ұ� ���� ������ pop�Ѵ�. (�޸� ���� ����)
//
template <typename Object>
Stack<Object>::~Stack()
{
    while (size_ > 0)
        pop();
}
 
// push(): �Է¹��� �����͸� ���� ����� ���ÿ� �ִ´�.
//
template <typename Object>
void Stack<Object>::push(const Object& o)
{
    NodePtr tmp = new Node;
    tmp->obj = o;
    tmp->next = empty()? NULL : top_;
 
    top_ = tmp;
    size_++;
}
 
// pop(): �� ���� ���Ҹ� ����Ʈ���� �����ϰ� ���� �Ҵ��� �޸𸮸� �����Ѵ�.
//
template <typename Object>
void Stack<Object>::pop()
{
    NodePtr tmp = top_;
 
    top_ = top_->next;
    size_--;
 
    delete tmp;
}
 
// top(): �� ���� ���Ҹ� ��ȯ�Ѵ�.
//
template <typename Object>
Object& Stack<Object>::top()
{
    return top_->obj;
}
 
// top(): �� ���� ���Ҹ� ��� ��ü�� ��ȯ�Ѵ�.
//
template <typename Object>
const Object Stack<Object>::top() const
{
    return top_->obj;
}
 
// size(): ���ÿ� ����� �������� ������ ��ȯ�Ѵ�.
//
template <typename Object>
int Stack<Object>::size() const
{
    return size_;
}
 
// empty(): ������ ������� true, �ƴϸ� false�� ��ȯ�Ѵ�.
//
template <typename Object>
bool Stack<Object>::empty() const
{
    return (size_ == 0);
}
