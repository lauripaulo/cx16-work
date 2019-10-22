
struct _game_obj
{
  uint16_t x;
  uint16_t y;
  uint16_t addr;
  uint16_t data_addr;
  uint8_t data[];
};

typedef struct _game_obj GameObj;

static void vpoke(uint8_t bank, uint16_t address, uint8_t data);

static void init_player(GameObj *p);
