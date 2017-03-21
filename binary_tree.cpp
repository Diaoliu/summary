template <typename T>
class Node {

private:

  T element;
  Node *left;
  Node *right;

public:

  Node(T const &obj) : element(obj), left(0), right(0) {
      /* omitted */
  }

  T retrieve() const {
    return element;
  }

  Node* left() const {
    return left;
  };

  Node* right() const  {
    return right;
  };

  int size() const {
    return (this = 0)? 0 : 1 + left->size() + right->size();
  }

  int height() const;
  bool leaf() const {
     return ( ( left == 0 ) && ( right == 0 ) );
  }

  T front() const {
    return (left == 0)? element : left->front();
  }

  T back() const {
    return (right == 0)? element : left->back();
  }

  int count(const T & obj) const {
    if (this == 0)
      return 0;
    else if (obj == element)
      return 1;
    else if (obj < element)
      return left->count(obj);
    else
     return right->count(obj);
  };

  void clear() {
    if (this == 0)
      return;
    left->clear();
    right->clear();
    delete this;
  }

  void insert(T const & obj) {
    if (obj < element) {
      if (left)
        left->insert(obj);
      else
        left = new Node<T>(obj);
    } else if (obj > element) {
      if (right)
        right->insert(obj);
      else
        right = new Node<T>(obj);
    }
  }

  int erase(T const &obj, Node *& ptr_to_this) {
    if (obj == element) {
      if (leaf()) {
        ptr_to_this = 0;
        delete this;
      } else if(left && right) {
        element = right->front();
        right->erase( element, right);
      } else {
         ptr_to_this = (left != 0)? left : right;
         delete this;
      }
    } else if(obj < element) {
      return (left == 0)? 0 : left->erase(obj, left);
    } else if(obj > element) {
      return (right == 0)? 0 : right->erase(obj, right);
    }
  }

  friend class Binary_search_tree<T>;
};
