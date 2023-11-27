
namespace load{

    class context
    {
    public:
        static instance_t get_instance_initialize(){
            return get_instance();
        }
    };
    
}
