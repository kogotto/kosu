#ifndef MENU_DETAIL_HPP
#define MENU_DETAIL_HPP


namespace ks {
namespace menu_detail {

enum class Item {
    NewGame,
    Exit,

    Count
};

Item prev(Item item);
Item next(Item item);

} // namespace menu_detail
} // namespace ks


#endif // MENU_DETAIL_HPP
