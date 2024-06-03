#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

class strBlobPtr;

class strBlob
{
public:
  using container_type = std::vector<std::string>;
  using size_type = container_type::size_type;
  using value_type = container_type::value_type;

private:
  std::shared_ptr<container_type> container_ptr;

public:
  strBlob()
      : container_ptr(std::make_shared<container_type>()) {}
  strBlob(std::initializer_list<value_type> il)
      : container_ptr(std::make_shared<container_type>(il)) {}
  ~strBlob() = default;

  size_type size() const
  {
    return container_ptr->size();
  }

  auto push_back(value_type value)
  {
    return container_ptr->push_back(value);
  }
  auto pop_back()
  {
    check_range(0, "pop_back() on a empty blob");
    return container_ptr->pop_back();
  }

  auto &front()
  {
    check_range(0, "front() on a empty blob");
    return container_ptr->front();
  }
  const auto &front() const
  {
    check_range(0, "front() on a empty blob");
    return container_ptr->front();
  }
  auto &back()
  {
    check_range(0, "back() on a empty blob");
    return container_ptr->back();
  }
  const auto &back() const
  {
    check_range(0, "back() on a empty blob");
    return container_ptr->back();
  }

  auto empty() const
  {
    return container_ptr->empty();
  }

  auto use_count() const
  {
    return container_ptr.use_count();
  }

  strBlobPtr begin();
  strBlobPtr end();

private:
  void check_range(size_type i, const std::string &msg) const
  {
    if (i >= container_ptr->size())
      throw std::out_of_range(msg);
  }

  friend class strBlobPtr;
};

class strBlobPtr
{
  std::weak_ptr<strBlob::container_type> w_ptr;
  strBlob::size_type cur;

  std::shared_ptr<strBlob::container_type> check(strBlob::size_type i, const std::string &msg)
  {
    auto p = w_ptr.lock();
    if (!p)
      throw std::runtime_error("access a non_exist object");
    else if (i >= p->size())
      throw std::out_of_range(msg);
    return p;
  }

public:
  strBlobPtr() : cur(0) {}
  strBlobPtr(strBlob &blob, strBlob::size_type c = 0)
      : w_ptr(blob.container_ptr), cur(c) {}

  strBlob::value_type &deref()
  {
    auto p = check(cur, "deref a strBlobPtr out of range");
    return (*p)[cur];
  }

  strBlobPtr &incr()
  {
    check(cur, "incr a cur just past the last element");
    ++cur;
    return *this;
  }
};

inline strBlobPtr strBlob::begin()
{
  return strBlobPtr(*this);
}
inline strBlobPtr strBlob::end()
{
  return strBlobPtr(*this, container_ptr->size());
}
