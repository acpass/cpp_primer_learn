#ifndef _SALE_ITEM_HPP_
#define _SALE_ITEM_HPP_

#include <string>

struct Sale_item
{
  std::string BookNO;
  unsigned int unit_sold = 0;
  double revenue = 0.0;

  // considered as Sale_item::isbn(const Sale_item *const this)
  // the const after the parameters changed the low-level constness of the implicit parameter 'this'
  std::string isbn() const { return BookNO; }; // implicitly use this->ISBN

  /*
  considered as Sale_item::combine(Sale_item *const this, const Sale_item &)
  !! A low-level const object of type Sale_item can't be used to initializing the non-low-level const 'this' in this function
  !! so a const Sale_item object can't be used to involke combine function
  */
  Sale_item &combine(const Sale_item &);
  double avg_price() const { return 0; };
};

Sale_item add(const Sale_item &, const Sale_item &);
std::ostream &print(std::ostream &, const Sale_item &);
std::istream &read(std::istream &, Sale_item &);

inline Sale_item &Sale_item::combine(const Sale_item &item)
{
  unit_sold += item.unit_sold;
  revenue += item.revenue;
  return *this;
}

#endif