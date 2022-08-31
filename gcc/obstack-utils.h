// Obstack-related utilities.
// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef GCC_OBSTACK_UTILS_H
#define GCC_OBSTACK_UTILS_H

// This RAII class automatically frees memory allocated on an obstack,
// unless told not to via keep ().  It automatically converts to an
// obstack, so it can (optionally) be used in place of the obstack
// to make the scoping clearer.  For example:
//
//     obstack_watermark watermark (ob);
//     auto *ptr1 = XOBNEW (watermark, struct1);
//     if (...)
//       // Frees ptr1.
//       return false;
//
//     auto *ptr2 = XOBNEW (watermark, struct2);
//     if (...)
//       // Frees ptr1 and ptr2.
//       return false;
//
//     // Retains ptr1 and ptr2.
//     watermark.keep ();
//
//     auto *ptr3 = XOBNEW (watermark, struct3);
//     if (...)
//       // Frees ptr3.
//       return false;
//
//     // Retains ptr3 (in addition to ptr1 and ptr2 above).
//     watermark.keep ();
//     return true;
//
// The move constructor makes it possible to transfer ownership to a caller:
//
//     obstack_watermark
//     foo ()
//     {
//       obstack_watermark watermark (ob);
//       ...
//       return watermark;
//     }
//
//     void
//     bar ()
//     {
//       // Inherit ownership of everything that foo allocated.
//       obstack_watermark watermark = foo ();
//       ...
//     }
class obstack_watermark
{
public:
  obstack_watermark (obstack *ob) : m_obstack (ob) { keep (); }
  constexpr obstack_watermark (obstack_watermark &&) = default;
  ~obstack_watermark () { obstack_free (m_obstack, m_start); }

  operator obstack *() const { return m_obstack; }
  void keep () { m_start = XOBNEWVAR (m_obstack, char, 0); }

private:
  DISABLE_COPY_AND_ASSIGN (obstack_watermark);

protected:
  obstack *m_obstack;
  char *m_start;
};

#endif
