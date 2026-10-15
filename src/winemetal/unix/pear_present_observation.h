/* Original Pear finite observation, reusing #7 witnesses. SPDX-License-Identifier: MIT. */
#import <objc/runtime.h>
static unsigned long pear_present_sequence;
static unsigned long pear_life_created[3],pear_life_dead[3];
static char pear_life_keys[3];
static int pear_present_observing(void) { const char *p=getenv("PEAR_PRESENT_OBSERVE");return p && !strcmp(p,"1"); }
@interface PearPresentWitness : NSObject { unsigned kind; unsigned long number; }
- (id)initWithKind:(unsigned)value;
@end
@implementation PearPresentWitness
- (id)initWithKind:(unsigned)value {
    self=[super init];if(self) { kind=value;number=__atomic_add_fetch(pear_life_created+kind,1,__ATOMIC_RELAXED);
        fprintf(stderr,"PEAR_PRESENT_LIFE action=create kind=%u number=%lu\n",kind,number); }return self;
}
- (void)dealloc {
    __atomic_add_fetch(pear_life_dead+kind,1,__ATOMIC_RELAXED);
    fprintf(stderr,"PEAR_PRESENT_LIFE action=destroy kind=%u number=%lu\n",kind,number);[super dealloc];
}
@end
static void pear_present_witness(id object,unsigned kind) {
    if(!object || kind>=3) return;
    if(!objc_getAssociatedObject(object,pear_life_keys+kind)) {
        PearPresentWitness *w=[[PearPresentWitness alloc] initWithKind:kind];
        objc_setAssociatedObject(object,pear_life_keys+kind,w,OBJC_ASSOCIATION_RETAIN_NONATOMIC);[w release];
    }
}
static void pear_present_layer(void *context,uint64_t value) {
    (void)context;CAMetalLayer *layer=(CAMetalLayer*)(uintptr_t)value;
    id view=layer.delegate;
    if(![view isKindOfClass:NSClassFromString(@"WineMetalView")]) return;
    pear_present_witness(view,0);pear_present_witness(layer,1);
}
static void pear_present_observe(id<MTLCommandBuffer> command,id<MTLDrawable> drawable) {
    if(!pear_present_observing()) return;
    unsigned long sequence=__atomic_add_fetch(&pear_present_sequence,1,__ATOMIC_RELAXED);
    fprintf(stderr,"PEAR_PRESENT_SUBMIT sequence=%lu drawable=%lu\n",sequence,(unsigned long)drawable.drawableID);
    [drawable addPresentedHandler:^(id<MTLDrawable> value) {
        fprintf(stderr,"PEAR_PRESENT_DISPLAY sequence=%lu drawable=%lu time=%.9f\n",sequence,(unsigned long)value.drawableID,value.presentedTime);
    }];
    [command addCompletedHandler:^(id<MTLCommandBuffer> value) {
        fprintf(stderr,"PEAR_PRESENT_GPU sequence=%lu status=%lu error=%ld\n",sequence,(unsigned long)value.status,(long)(value.error?value.error.code:0));
    }];
}
