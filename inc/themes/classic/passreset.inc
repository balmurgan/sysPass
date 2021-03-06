<div id="actions" align="center">

    <div id="logo">
        <img src="<?php use SP\Html;
        use SP\Util;

        echo $logo; ?>" alt="sysPass logo"/>
    </div>

    <form id="frmPassReset" action="" method="post"
          onsubmit="sysPassUtil.Common.sendAjax($(this).serialize(),'/ajax/ajax_passReset.php'); return false;">
        <fieldset id="resetdata">
            <legend><?php echo _('Solicitud de Cambio de Clave'); ?></legend>
            <?php if (!$passReset): ?>
                <p>
                    <input type="text" name="login" id="login" title="<?php echo _('Login del Usuario'); ?>"
                           placeholder="<?php echo _('Usuario'); ?> "
                           value="<?php echo Util::init_var('login'); ?>" autocomplete="off" autofocus required/>
                </p>
                <p>
                    <input type="text" name="email" id="email" title="<?php echo _('Email del Usuario'); ?>"
                           placeholder="<?php echo _('Email'); ?>  "
                           value="<?php echo Util::init_var('email'); ?>" autocomplete="off" autofocus required/>
                </p>
            <?php else: ?>
                <p>
                    <input type="password" name="pass" id="pass" title="<?php echo _('Nueva Clave'); ?>"
                           class="passwordfield__input"
                           placeholder="<?php echo _('Clave'); ?>" value="<?php echo Util::init_var('pass'); ?>"
                           required/>
                </p>
                <p>
                    <input type="password" name="passR" id="passR"
                           title="<?php echo _('Clave'); ?>"
                           placeholder="<?php echo _('Clave (repetir)'); ?>"
                           value="<?php echo Util::init_var('passR'); ?>" required/>
                </p>
                <input type="hidden" name="time" value="<?php echo $time; ?>">
                <input type="hidden" name="hash" value="<?php echo $hash; ?>">
            <?php endif; ?>
            <input type="hidden" name="isAjax" value="1">
            <input type="hidden" name="sk" value="<?php echo $sk; ?>">
        </fieldset>

        <div class="buttons">
            <?php echo Html::anchorText(_('Volver'), 'index.php', _('Volver a iniciar sesión'), 'class="button round5"'); ?>
            <?php if (!$passReset): ?>
                <input type="submit" class="button round5" value="<?php echo _('Solicitar'); ?>"
                       title="<?php echo _('Solicitar cambio de clave'); ?>"/>
            <?php else: ?>
                <input type="submit" class="button round5" value="<?php echo _('Cambiar'); ?>"
                       title="<?php echo _('Cambiar Clave'); ?>"/>
            <?php endif; ?>
        </div>
    </form>
</div>
<script>
    window.onload = function () {
        sysPassUtil.passwordDetect();

        $('#btnBack').click(function () {
            window.history.back();
        });

        $('#frmPassReset').submit(function () {
            sysPassUtil.Common.sendAjax($(this).serialize(), '/ajax/ajax_passReset.php');
            return false;
        });
    };
</script>