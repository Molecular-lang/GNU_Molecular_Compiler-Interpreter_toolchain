/* Pretty print support for value ranges. */

#ifndef GCC_VALUE_RANGE_PRETTY_H
#define GCC_VALUE_RANGE_PRETTY_H

class vrange_printer : public vrange_visitor
{
public:
  vrange_printer (pretty_printer *pp_) : pp (pp_) { }
  void visit (const unsupported_range &) const override;
  void visit (const irange &) const override;
  void visit (const frange &) const override;
private:
  void print_irange_bound (const wide_int &w, tree type) const;
  void print_irange_bitmasks (const irange &) const;
  void print_frange_nan (const frange &) const;
  void print_real_value (tree type, const REAL_VALUE_TYPE &r) const;

  pretty_printer *pp;
};

#endif // GCC_VALUE_RANGE_PRETTY_H
