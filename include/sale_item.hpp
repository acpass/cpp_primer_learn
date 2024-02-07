#ifndef _SALE_ITEM_HPP_
#define _SALE_ITEM_HPP_

#include <string>

class Sale_item
{

private:
  std::string BookNO;
  unsigned int unit_sold = 0;
  double revenue = 0.0;

  double avg_price() const { return unit_sold == 0 ? 0 : revenue / unit_sold; };

public:
  // constructors-------------
  //  default constructor
  Sale_item() = default;
  Sale_item(const std::string &s)
      : BookNO(s) {}
  Sale_item(const std::string &s, unsigned int unit, double price)
      : BookNO(s), unit_sold(unit), revenue(price * unit) {}
  Sale_item(std::istream &is);
  // constructors------------

  //  considered as Sale_item::isbn(const Sale_item *const this)
  //  the const after the parameters changed the low-level constness of the implicit parameter 'this'
  std::string isbn() const { return BookNO; }; // implicitly use this->ISBN
  /*
  considered as Sale_item::combine(Sale_item *const this, const Sale_item &)
  !! A low-level const object of type Sale_item can't be used to initializing the non-low-level const 'this' in this function
  !! so a const Sale_item object can't be used to involke combine function
  */
  Sale_item &combine(const Sale_item &);

  // friend specifier makes enable following declared functions to access private members
  // just about friendship, not a normal declaration
  friend Sale_item add(const Sale_item &, const Sale_item &);
  friend std::ostream &print(std::ostream &, const Sale_item &);
  friend std::istream &read(std::istream &, Sale_item &);
};

// although there are friend declaration, following general declarations are necessary
// some compilers may allow absence of following odinary declarations
Sale_item add(const Sale_item &, const Sale_item &);
std::ostream &print(std::ostream &, const Sale_item &);
std::istream &read(std::istream &, Sale_item &);

inline Sale_item &Sale_item::combine(const Sale_item &item)
{
  unit_sold += item.unit_sold;
  revenue += item.revenue;
  return *this;
}

inline Sale_item::Sale_item(std::istream &is)
{
  read(is, *this);
}

#endif