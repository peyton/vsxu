class module_texture_load_bitmap2texture : public vsx_module
{
  // in
  vsx_module_param_bitmap* bitm_in;
  vsx_module_param_int* mipmaps;

  // out
  vsx_module_param_texture* result_texture;

  // internal
  float time;
  vsx_bitmap* bitm;
  int bitm_timestamp;
  vsx_texture* texture;

public:

  void module_info(vsx_module_info* info)
  {
    info->identifier =
      "texture;loaders;bitmap2texture";

    info->description =
      "";

    info->in_param_spec =
      "bitmap:bitmap,mipmaps:enum?yes|no";

    info->out_param_spec =
      "texture:texture";

    info->component_class =
      "texture";
  }

  void declare_params(vsx_module_param_list& in_parameters, vsx_module_param_list& out_parameters)
  {

    bitm_in = (vsx_module_param_bitmap*)in_parameters.create(VSX_MODULE_PARAM_ID_BITMAP,"bitmap");
    mipmaps = (vsx_module_param_int*)in_parameters.create(VSX_MODULE_PARAM_ID_INT,"mipmaps");
    mipmaps->set(0);

    bitm_timestamp = 0;
    texture = new vsx_texture;
    texture->init_opengl_texture_2d();

    result_texture = (vsx_module_param_texture*)out_parameters.create(VSX_MODULE_PARAM_ID_TEXTURE,"texture");
    loading_done = true;
  }

  void run()
  {
    bitm = bitm_in->get_addr();
    if (!bitm)
    {
      result_texture->valid = false;
      return;
    }

    if (bitm->valid && bitm_timestamp != bitm->timestamp)
    {
      // ok, new version
      bitm_timestamp = bitm->timestamp;
      if (mipmaps->get() == 0)
      texture->upload_ram_bitmap_2d(bitm,true);
      else
      texture->upload_ram_bitmap_2d(bitm,false);
      result_texture->set(texture);
    }
  }

  void stop()
  {
    texture->unload();
  }

  void start()
  {
    texture->init_opengl_texture_2d();
    bitm = bitm_in->get_addr();
    if (bitm) {
      texture->upload_ram_bitmap_2d(bitm,mipmaps->get());
      result_texture->set(texture);
    }
  }

  void on_delete()
  {
    texture->unload();
    delete texture;
  }

};


