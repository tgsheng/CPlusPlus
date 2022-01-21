template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
  List<elemType>();
  List<elemType>(const List<elemType> &);
  List<elemType> &operator=(const List<elemType> &);
  ~List();
  // void insert(ListItem *ptr, elemType value); // errno: template is not a type
  void insert(ListItem<elemType> *ptr, elemType value);

private:
  // ListItem *front, *end; // errno: template is not a type
  ListItem<elemType> *front, *end;
};