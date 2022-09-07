/* JSON trees
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_JSON_H
#define GCC_JSON_H

/* Implementation of JSON, a lightweight data-interchange format.

   See http://www.json.org/
   and http://www.ecma-international.org/publications/files/ECMA-ST/ECMA-404.pdf
   and https://tools.ietf.org/html/rfc7159

   Supports creating a DOM-like tree of json::value *, and then dumping
   json::value * to text.  */

namespace json
{

/* Forward decls of json::value and its subclasses (using indentation
   to denote inheritance.  */

class value;
  class object;
  class array;
  class float_number;
  class integer_number;
  class string;
  class literal;

/* An enum for discriminating the subclasses of json::value.  */

enum kind
{
  /* class json::object.  */
  JSON_OBJECT,

  /* class json::array.  */
  JSON_ARRAY,

  /* class json::integer_number.  */
  JSON_INTEGER,

  /* class json::float_number.  */
  JSON_FLOAT,

  /* class json::string.  */
  JSON_STRING,

  /* class json::literal uses these three values to identify the
     particular literal.  */
  JSON_TRUE,
  JSON_FALSE,
  JSON_NULL
};

/* Base class of JSON value.  */

class value
{
 public:
  virtual ~value () {}
  virtual enum kind get_kind () const = 0;
  virtual void print (pretty_printer *pp) const = 0;

  void dump (FILE *) const;
};

/* Subclass of value for objects: an unordered collection of
   key/value pairs.  */

class object : public value
{
 public:
  ~object ();

  enum kind get_kind () const final override { return JSON_OBJECT; }
  void print (pretty_printer *pp) const final override;

  void set (const char *key, value *v);
  value *get (const char *key) const;

 private:
  typedef hash_map <char *, value *,
    simple_hashmap_traits<nofree_string_hash, value *> > map_t;
  map_t m_map;
};

/* Subclass of value for arrays.  */

class array : public value
{
 public:
  ~array ();

  enum kind get_kind () const final override { return JSON_ARRAY; }
  void print (pretty_printer *pp) const final override;

  void append (value *v);

 private:
  auto_vec<value *> m_elements;
};

/* Subclass of value for floating-point numbers.  */

class float_number : public value
{
 public:
  float_number (double value) : m_value (value) {}

  enum kind get_kind () const final override { return JSON_FLOAT; }
  void print (pretty_printer *pp) const final override;

  double get () const { return m_value; }

 private:
  double m_value;
};

/* Subclass of value for integer-valued numbers.  */

class integer_number : public value
{
 public:
  integer_number (long value) : m_value (value) {}

  enum kind get_kind () const final override { return JSON_INTEGER; }
  void print (pretty_printer *pp) const final override;

  long get () const { return m_value; }

 private:
  long m_value;
};


/* Subclass of value for strings.  */

class string : public value
{
 public:
  string (const char *utf8);
  ~string () { free (m_utf8); }

  enum kind get_kind () const final override { return JSON_STRING; }
  void print (pretty_printer *pp) const final override;

  const char *get_string () const { return m_utf8; }

 private:
  char *m_utf8;
};

/* Subclass of value for the three JSON literals "true", "false",
   and "null".  */

class literal : public value
{
 public:
  literal (enum kind kind) : m_kind (kind) {}

  /* Construct literal for a boolean value.  */
  literal (bool value): m_kind (value ? JSON_TRUE : JSON_FALSE) {}

  enum kind get_kind () const final override { return m_kind; }
  void print (pretty_printer *pp) const final override;

 private:
  enum kind m_kind;
};

} // namespace json

#endif  /* GCC_JSON_H  */
