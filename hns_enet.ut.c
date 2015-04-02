#define UT_DUMPSTACK
#include "comm.h"

static void writel_relaxed(u32 val, volatile void __iomem *addr) {
}
extern u32 readl_relaxed(const volatile void __iomem *addr) {
	return 0;
}

static struct sk_buff *netdev_alloc_skb(struct net_device *dev, unsigned int length) {
	return NULL;
}

struct skb_shared_info {
	unsigned char	nr_frags;
	u8		tx_flags;
	unsigned short	gso_size;
	unsigned short	gso_segs;
	unsigned short  gso_type;
	struct sk_buff	*frag_list;
//	struct skb_shared_hwtstamps hwtstamps;
	u32		tskey;
	u32          ip6_frag_id;

/*
	atomic_t	dataref;
	*/
	void *		destructor_arg;
	skb_frag_t	frags[10];
};

struct skb_shared_info *skb_shared_info1;
struct skb_shared_info *skb_shinfo(struct sk_buff *buf) {
	return skb_shared_info1;
}

struct netdev_queue *netdev_get_tx_queue(const struct net_device *dev,
                                         unsigned int index) {
	return NULL;
}

static void netdev_tx_completed_queue(struct netdev_queue *dev_queue,
                                             unsigned int pkts, unsigned int bytes) {
}

static void dev_kfree_skb_any(struct sk_buff *skb) {
}

static bool netif_tx_queue_stopped(const struct netdev_queue *dev_queue) {
	return 1;
}

void netif_tx_wake_queue(struct netdev_queue *dev_queue) {

}

static void napi_schedule(struct napi_struct *n) {
}

void netif_napi_del(struct napi_struct *napi) {}
void netif_carrier_on(struct net_device *dev) {}


void *platform_get_drvdata(struct platform_device *dev){
	return NULL;
}

#define to_platform_device(val) NULL

int ntohs(int val) {
	return 0;
}

struct iphdr {
	int protocol;
	int nexthdr;
};
struct ipv6hdr {
	int protocol;
	int nexthdr;
};
struct iphdr *ip_hdr(struct sk_buff *skb) {
	return NULL;
}
struct ipv6hdr *ipv6_hdr(struct sk_buff *skb) {
	return NULL;
}

void *netdev_priv(struct net_device *ndev);

static void *kzalloc(size_t size, int flags) {
	return NULL;
}

static bool is_valid_ether_addr(const u8 *addr) {
	return 1;
}

int phy_ethtool_sset(struct phy_device *phydev, struct ethtool_cmd *cmd) {
	return 0;
}

u32 ethtool_op_get_link(struct net_device *dev) {
	return 0;
}

const void *of_get_mac_address(struct device_node *np) {
	return NULL;
}
struct net_device *alloc_etherdev_mq(int sizeof_priv, unsigned int txqs) {
	return NULL;
}
static int dma_set_mask_and_coherent(struct device *dev, u64 mask) {
	return 0;
}


int skb_headlen_data=0;
static unsigned int skb_headlen(const struct sk_buff *skb) {
	return skb_headlen_data;
}
#define MAPPED_DMA 0x8989
#define UNMAPPED_DMA 0x7f7f
static int dma_mapping_cnt1;
int tc110_dma_check[3];
static dma_addr_t dma_map_single(struct device *dev, void *cpu_addr, size_t size,
               int dir) {
	if(testcase==110) {
		tc110_dma_check[dma_mapping_cnt1] = 1;
	}
	return MAPPED_DMA;
}
static int dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
	if(testcase == 108) {
		return 1;
	}

	if(testcase == 110) {
		if(dma_mapping_cnt1==4)
			return 1;
		else
			return 0;
	}

        return 0;
}

static unsigned int skb_frag_size(const skb_frag_t *frag) {
	return 10;
}
static dma_addr_t skb_frag_dma_map(struct device *dev, 
	const skb_frag_t *frag, size_t offset, size_t size, int dir) {
	if(testcase == 110) {
		tc110_dma_check[dma_mapping_cnt1++]=1;
	}
	return 0x8989;
}
static void dma_unmap_page(struct device *dev, dma_addr_t dma_handle,
               size_t size, int dir)
{
	ut_assert(dma_handle==MAPPED_DMA);
	ut_assert(size==10);
	if(testcase == 110) {
		ut_assert(tc110_dma_check[dma_mapping_cnt1-1]==1);
		tc110_dma_check[dma_mapping_cnt1-1] = 2;
		dma_mapping_cnt1--;
	}
}
static void dma_unmap_single(struct device *dev, dma_addr_t dma_addr,
                 size_t size, int dir)
{
	ut_assert(dma_addr==MAPPED_DMA);
	ut_assert(size==500);
	if(testcase==110) {
		ut_assert(dma_mapping_cnt1 == 1);
		ut_assert(tc110_dma_check[0] == 1);
		tc110_dma_check[0] = 2;
	}
}

short eth_type_trans(struct sk_buff *skb, struct net_device *dev) { return 0; } 
int napi_gro_receive(struct napi_struct *napi, struct sk_buff *skb) {
	return 0;
}

static void netif_tx_lock(struct net_device *dev) {
}

static void netif_tx_unlock(struct net_device *dev) {}
void napi_complete(struct napi_struct *n) {}
typedef irqreturn_t (*irq_handler_t)(int, void *);
static int request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags,
            const char *name, void *dev) {
	return 0;
}

int IS_ERR(void *ptr) {
	return 0;
}

int PTR_ERR(void *ptr) {
	return 0;
}

int netif_set_real_num_tx_queues(struct net_device *dev, unsigned int txq) {
	return 0;
}
int netif_set_real_num_rx_queues(struct net_device *dev, unsigned int txq) {
	return 0;
}
static void netdev_reset_queue(struct net_device *dev_queue) {
}
static inline void netif_start_queue(struct net_device *dev) {}
static inline void netif_stop_queue(struct net_device *dev){}
void netif_carrier_off(struct net_device *dev) {}
struct hnae_handle;
struct hnae_rb_buf_ops;
unsigned char *skb_put(struct sk_buff *skb, unsigned int len) {
	return NULL;
}
void netif_napi_add(struct net_device *dev, struct napi_struct *napi,
                    int (*poll)(struct napi_struct *, int), int weight) {
}
void kfree(const void *objp){}
#define local_irq_save(flags)
#define local_irq_restore(flags) 
int phy_ethtool_gset(struct phy_device *phydev, struct ethtool_cmd *cmd) {
	return 0;
}
static void eth_hw_addr_random(struct net_device *dev) {
}
static inline void platform_set_drvdata(struct platform_device *pdev, void *data) {}
int of_get_phy_mode(struct device_node *np) {
	return 0;
}
int of_property_read_string(struct device_node *np, const char *propname,
                                const char **out_string) {
	return 0;
}
int kstrtoint(const char *s, unsigned int base, int *res) {
	return 0;
}

int register_netdev(struct net_device *dev) {
	return 0;
}
void free_netdev(struct net_device *dev) {}
void unregister_netdev(struct net_device *dev) {}

static void ether_addr_copy(u8 *dst, const u8 *src) {}

static __attribute__((unused)) struct platform_driver hns_nic_dev_driver;

struct timer_list {};
struct work_struct {};
int mod_timer(struct timer_list *timer, unsigned long expires){
	return 0;
}
static inline bool netif_carrier_ok(const struct net_device *dev) {
	return 0;
}
static inline bool schedule_work(struct work_struct *work) {
	return 0;
}

#include "hns_enet.c"

struct hnae_handle *my_get_handle(struct hnae_ae_dev *dev, const char *opts,
                struct hnae_rb_buf_ops *bops) {
	return NULL;
}

#define TEST_Q_NUM 8
struct hns_nic_priv priv1;
struct hnae_handle_k {
	struct device *owner_dev;
	struct hnae_ae_dev *dev;
	int q_num;
	struct hnae_queue qs[TEST_Q_NUM];
}handle_k;
struct hnae_handle *handle1 = (struct hnae_handle *)&handle_k;
struct hnae_ae_ops ops = {
	.get_handle = my_get_handle,
};
struct hnae_ring *tx_ring1;
struct hnae_ring *rx_ring1;
void *netdev_priv(struct net_device *ndev) {
	int i;
	priv1.ae_handle = handle1;
	handle1->q_num = TEST_Q_NUM;
	
	for(i=0; i<TEST_Q_NUM; i++) {
		handle1->qs[i].handle = handle1;
		handle1->qs[i].rx_ring = rx_ring1;
		handle1->qs[i].tx_ring = tx_ring1;
	}
	return &priv1;
}


void hnae_put_handle(struct hnae_handle *handle) {};
struct hnae_handle * hnae_get_handle(struct device * owner_dev,
        const char *ae_id, const char *ae_opts, struct hnae_rb_buf_ops *bops) {
	return NULL;
}

static inline void clear_desc(struct hnae_rb_desc *desc) {
	int i;
	for(i=0;i<16;i++) {
		desc[i].addr=UNMAPPED_DMA;
	}
}

static inline void validate_desc(struct hnae_rb_desc *desc, int start, int end) {
	int i;
	for(i=0;i<16;i++) {
		if(end >= start)
			if((i>=start) && (i<end))
				ut_assert_str(desc[i].addr==MAPPED_DMA, "desc[%d]=0x%x", i, desc[i].addr);
			else
				ut_assert_str(desc[i].addr==UNMAPPED_DMA, "desc[%d]=0x%x", i, desc[i].addr);
		else
			if((i>=start) || (i<end))
				ut_assert_str(desc[i].addr==MAPPED_DMA, "desc[%d]=0x%x", i, desc[i].addr);
			else
				ut_assert_str(desc[i].addr==UNMAPPED_DMA, "desc[%d]=0x%x", i, desc[i].addr);

	}
}

void hns_ethtool_set_ops(struct net_device *ndev)
{}

void testcase_test_hns_nic_net_xmit_hw(void)
{
	struct net_device ndev;
	struct sk_buff skb;
	struct hns_nic_ring_data ring_data;
	struct hnae_ring ring;
	struct skb_shared_info info1;
	struct hnae_rb_desc_cb desc_cb[16];
	struct hnae_rb_desc desc[16];
	int ret;
	int i,j;
	tx_ring1 = &ring;

#define reset(tc) do {\
		testcase = tc;\
		printf("testcase %d...\n", tc);\
		ring_data.ring = &ring;\
		ring_data.tx_err_cnt = 1;\
		ring_data.pkt_cnt = 10;\
		ring_data.byte_cnt = 100;\
		ring.desc_num = 16;\
		ring.next_to_use = 3;\
		ring.next_to_clean = 10;/* 7 space */ \
		ring.desc_cb = desc_cb;\
		ring.desc = desc;\
		ndev.mtu = 1600;\
		skb.len = 1000;\
		skb.queue_mapping = 2;\
		skb_shared_info1 = &info1;\
		info1.nr_frags = 0;\
		skb_headlen_data = 500;\
		clear_desc(desc);\
	}while(0);

#define std_validate_no_send(busy) do {\
		if(busy) {\
			ut_assert_str(ret == NETDEV_TX_BUSY, "not return busy");\
			ut_assert_str(ring_data.tx_err_cnt == 1, "tx_err_cnt"); /*busy is NOT err*/ \
		}else {\
			ut_assert_str(ret == NETDEV_TX_OK, "not return ok"); \
			ut_assert_str(ring_data.tx_err_cnt == 2, "tx_err_cnt");\
		}\
		ut_assert_str(ring.next_to_use == 3, "next_to_use");\
		ut_assert_str(ring.next_to_clean == 10, "next_to_clean");\
		ut_assert_str(ring_data.pkt_cnt == 10, "pkt_cnt");\
		ut_assert_str(ring_data.byte_cnt == 100, "byte_cnt");\
	}while(0);

	//case1: invalid skb
	reset(101);
	skb.len = 0;
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	std_validate_no_send(0);
	validate_desc(desc, 0,0);
	

	reset(102);
	skb.len = -1;
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	std_validate_no_send(0);
	validate_desc(desc, 0,0);

	reset(103);
	skb.len = 1601;
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	std_validate_no_send(0);
	validate_desc(desc, 0,0);

	//case2: too much skb fragment
	reset(104);
	skb.len = 1600; //len == mtu? it should pass, right?
	info1.nr_frags = 17; //exactly 1 more
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	std_validate_no_send(0);
	validate_desc(desc, 0,0);

	reset(105);
	info1.nr_frags = -1;
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	std_validate_no_send(0);
	validate_desc(desc, 0,0);

	reset(106);
	info1.nr_frags = 7; //1 more than the space
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	std_validate_no_send(1);
	validate_desc(desc, 0,0);

	//case 3: test to pass where skb has no fragment
	reset(107);
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	ut_assert(ret == NETDEV_TX_OK);
	ut_assert(ring_data.tx_err_cnt == 1);
	ut_assert(ring.next_to_use == 4); //move forward
	ut_assert(ring.next_to_clean == 10); //no touch to end
	ut_assert(desc[3].tx.fe == 1); //one fragment only
	ut_assert(ring_data.pkt_cnt == 11);
	ut_assert(ring_data.byte_cnt == 1100);

	// move forward
	for(i=0; i<6; i++) {
		ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
		ut_assert(ret == NETDEV_TX_OK);
		ut_assert(ring_data.tx_err_cnt == 1);
		ut_assert(ring.next_to_use == 5+i); //move forward
		ut_assert(ring.next_to_clean == 10); //no touch to end
		ut_assert(desc[4+i].tx.fe == 1); //one fragment only
		ut_assert(ring_data.pkt_cnt == 12+i);
		ut_assert(ring_data.byte_cnt == 2100+i*1000);
	}

	// now it is full
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	ut_assert(ret == NETDEV_TX_BUSY);
	ut_assert(ring_data.tx_err_cnt == 1);
	ut_assert(ring.next_to_use == 10); //stop here
	ut_assert(ring.next_to_clean == 10); //no touch to end
	ut_assert(ring_data.pkt_cnt == 17);
	ut_assert(ring_data.byte_cnt == 7100);
	validate_desc(desc, 3,10);

	//case 4: test to fail where skb has no fragment
	reset(108);
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	std_validate_no_send(1);
	validate_desc(desc, 0,0);

	//case 5: test to pass where skb has fragment
	reset(109);
	info1.nr_frags = 6; //fill them all
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	ut_assert(ret == NETDEV_TX_OK);
	ut_assert(ring_data.tx_err_cnt == 1);
	ut_assert(ring.next_to_use == 10);
	ut_assert(ring.next_to_clean == 10);
	ut_assert(ring_data.pkt_cnt == 11);
	ut_assert(ring_data.byte_cnt == 1100);

	// now it is full
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	ut_assert(ret == NETDEV_TX_BUSY);
	ut_assert(ring_data.tx_err_cnt == 1);
	ut_assert(ring.next_to_use == 10); //stop here
	ut_assert(ring.next_to_clean == 10); //no touch to end
	ut_assert(ring_data.pkt_cnt == 11);
	ut_assert(ring_data.byte_cnt == 1100);
	validate_desc(desc, 3,10);

	//case 6: test to fail where skb has fragment
	reset(110);
	dma_mapping_cnt1 = 0;
	info1.nr_frags = 6; //fill them all
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	std_validate_no_send(1);
	for(i=0;i<4;i++) {
		ut_assert(tc110_dma_check[0] == 2);
	}

	//case 7: repeat test 5 with loop back ring number
	reset(111);
	info1.nr_frags = 8; //fill them all
	ring.next_to_use = 10;
	ring.next_to_clean = 3;
	ret = hns_nic_net_xmit_hw(&ndev, &skb, &ring_data);
	ut_assert_str(ret == NETDEV_TX_OK, "ret=%d", ret);
	ut_assert(ring_data.tx_err_cnt == 1);
	ut_assert(ring.next_to_use == 3);
	ut_assert_str(ring.next_to_clean == 3, "next_to_clean=%d", ring.next_to_clean);
	ut_assert_str(ring_data.pkt_cnt == 11, "pkt_cnt=%d", ring_data.pkt_cnt);
	ut_assert(ring_data.byte_cnt == 1100);
	validate_desc(desc, 10, 3);
}

int main(void) {
	testcase_test_hns_nic_net_xmit_hw();
	return 0;
}

