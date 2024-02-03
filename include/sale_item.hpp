#ifndef _SALE_ITEM_HPP_
#define _SALE_ITEM_HPP_

#include <string>

struct Sale_item
{
  std::string ISBN;
  unsigned int unit_sold = 0;
  double revenue = 0.0;

  // considered as Sale_item::isbn(const Sale_item *const this)
  // the const after the parameters changed the top-level constness of the implicit parameter 'this'
  const std::string &isbn() const { return ISBN; }; // implicitly use this->ISBN

  /*
  considered as Sale_item::combine(Sale_item *const this, const Sale_item &)
  !! A top-level const object of type Sale_item can't be used to initializing the non-top-level const 'this' in this function
  !! so a const Sale_item object can't involke combine function
  */
  Sale_item &combine(const Sale_item &){

  };
  double avg_price() const {

  };
};

inline Sale_item add(const Sale_item &, const Sale_item &);
inline std::ostream print(std::ostream &, const Sale_item &);
inline std::istream read(std::istream, Sale_item &);

#endif