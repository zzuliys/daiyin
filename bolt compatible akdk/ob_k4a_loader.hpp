
class load{
public:
    static instance_t get_instance_by_file_name(dll_file_name){
        get_instance(dll_file_name);
    }
};



class device{
public:
    device(instance_t instance, k4a_device_t dev_handle):instance_(instance),dev_handle_(dev_handle) {

    }


    void start_cameras(k4a_config_t config){
        instance->start_cameras(dev_handle, config);
    }

    bool get_capture(capture *cap, std::chrono::milliseconds timeout)
    {
        k4a_capture_t capture_handle = nullptr;
        int32_t timeout_ms = internal::clamp_cast<int32_t>(timeout.count());
        k4a_wait_result_t result = k4a_device_get_capture(m_handle, &capture_handle, timeout_ms);
        if (result == K4A_WAIT_RESULT_FAILED)
        {
            throw error("Failed to get capture from device!");
        }
        else if (result == K4A_WAIT_RESULT_TIMEOUT)
        {
            return false;
        }

        *cap = capture(instance_, capture_handle);
        return true;
    }

    static device open(uint32_t index, dll_file_path){
        instance = get_instance(dll_file_name);
        k4a_device_t device_handle = instance->open_device(index);
        return device(instance, device_handle);   
    }

    static device open(uint32_t index, instance_t instance){
        instance_ = instance;
        k4a_device_t device_handle = instance->open_device(index);
        return device(instance, device_handle);   
    }

private:
    instance_t instance_;
    k4a_device_t dev_handle_;
    
};
