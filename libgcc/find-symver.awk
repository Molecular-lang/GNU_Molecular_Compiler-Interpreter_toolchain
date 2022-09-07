# Extract the version of a single symbol from the version map.
# Please review: $(src-dir)/SPL-README for Licencing info.

/^[A-Z]/ {
  version = $1;
  next;
}

$1 == symbol {
  print version
  exit
}
