#ifndef UFDT_PROP_DICT_H
#define UFDT_PROP_DICT_H

struct fdt_property;

struct ufdt_prop_dict {
  int mem_size;
  int num_used;
  void *fdtp;
  const struct fdt_property **props;
};

/*
 * Allocates some new spaces and creates a new ufdt_prop_dict.
 *
 * @return: a pointer to the newly created ufdt_prop_dict or
 *          NULL if dto_malloc failed
 */
int ufdt_prop_dict_construct(struct ufdt_prop_dict *dict, void *fdtp);

/*
 * Frees all space dto_malloced, not including ufdt_nodes in the table.
 */
void ufdt_prop_dict_destruct(struct ufdt_prop_dict *dict);

/*
 * Adds a fdt_property (as pointer) to the ufdt_prop_dict.
 * @return: 0 if success
 *          < 0 otherwise
 *
 * @Time: O(length of node->name)
 */
int ufdt_prop_dict_add(struct ufdt_prop_dict *dict,
                       const struct fdt_property *prop);

/*
 * Returns the pointer to the fdt_property with name
 *
 * @return: a pointer to the node or
 *          NULL if no such node in ufdt_prop_dict with same name.
 *
 * @Time: O(len = |name|)
 */
const struct fdt_property *ufdt_prop_dict_find(const struct ufdt_prop_dict *dict,
                                               const char *name);

#endif
